library(igraph)
library(dplyr)
library(ggplot2)

ratings_raw <- readLines("data/ratings.dat")
ratings_raw <- gsub("::", ",", ratings_raw)
ratings_data <- read.table(text=ratings_raw, sep=',') %>% as.data.frame(stringsAsFactors=F)

colnames(ratings_data) <- c('UserId', 'MovieId', 'Rating', 'Timestamp')
head(ratings_data)

ratings_data$MovieId <- ratings_data$MovieId %>% as.factor()

movieid_count = ratings_data %>% group_by('MovieId' = ratings_data$MovieId) %>% summarise(Count = n())

movieid_count$MovieId <- factor(movieid_count$MovieId, levels=unique(movieid_count[order(-movieid_count$Count), ])$MovieId, ordered=T)

movieid_count <- movieid_count[order(-movieid_count$Count), ]
ggplot(movieid_count[1:20, ], aes(x = MovieId, y = Count)) + 
  theme_bw() +
  scale_fill_manual(guide = FALSE) +
  ggtitle("Bar plot for count of MovieId") +
  theme(
    axis.text.x=element_text(angle = 45, vjust = 1, size = 9, hjust = 1)
  ) +
  xlab("MovieId") +
  ylab("Count") +
  geom_bar(stat="identity", fill='skyblue')


