# Topic: [Week 11] Crawling Twitter Big data, Text mining and visualization

# install packages for crawling and textmining and visualization
install.packages('twitteR')
install.packages('httr')
install.packages('curl')
install.packages('rJava')
install.packages('wordcloud')
install.packages('KoNLP')
library(twitteR)
library(httr)
library(curl)
library(rJava)
library(wordcloud)
library(KoNLP)


# Store developer token and key value in variable for OAuth public authentication on Twitter
consumer_key <- "2Bb9nUvZbwSZ3AgjqIX0kKMVP"
consumer_secret <- "95NOa4Cdq7oNmZ9nm8WHbLEZCcFgayY3QpOIzLj2w6M4mSZgna"

access_token <- "2916938285-ACySeCniMINpWY1cLU0JKMJVeAMPu8hiAz0Tlwl"
access_secret <- "LovZrwTUilswO9LAUNu3nNBMsD5BIu8p6TrMp187B6AFO"

# Setting up OAuth public authentication on Twitter
setup_twitter_oauth(consumer_key, consumer_secret, access_token, access_secret)

# Set Twitter keywords to crawl
keyword <- "Corona"

# Crawl the data corresponding to the keyword from Twitter and store it in a variable
data <- searchTwitter(keyword, n=500)

# Store crawled data as data frames
data.df <- twListToDF(data)

# Save converted data frame as text file
write(data.df$text, "Corona.txt")

# Read the saved text file line by line and store it in a variable
twitterPosts <- readLines("Corona.txt")

# Remove NA data from data
twitterPosts <- twitterPosts[!is.na(twitterPosts)]

# Extract only nouns from data
twitterWords <- sapply(twitterPosts,extractNoun,USE.NAMES=F)

# Remove dots, numbers, spaces, and other unnecessary words from data extracted only from nouns
interest<-gsub("[[:punct:][:digit:][:space:]]", "", unlist(twitterWords))
interest<-gsub("https", "", unlist(interest))
interest<-gsub("@", "", unlist(interest))

# Sort only words longer than 3 words
interest <- Filter(function(x) {nchar(x) > 3}, interest)

# Converting classified data into table data grouped by frequency
word_count <- table(interest)
# Output the top 30 words of frequency
head(sort(word_count, decreasing = T), 30)

# Visualize words with a minimum frequency of 5 or more in wordcloud
palette <- brewer.pal(8, "Set2")
wordcloud(names(word_count), freq=word_count, rot.per = 0.25, min.freq = 5, 
          random.order = F, random.color = T, colors=palette)

