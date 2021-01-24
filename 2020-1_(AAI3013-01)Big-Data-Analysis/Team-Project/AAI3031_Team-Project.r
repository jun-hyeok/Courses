## You can uncomment and run single hash-tagged lines
## Pseudo code start with UPPERCASE verb
## Install R packages to use if not already installed
## command: install.packages('packagename')

# install.packages('tm') # Install dependencies together
## dependency package required for loading 'tm' package: 'NLP'...

# install.packages('textstem') # Install dependencies together
## dependency packages required for loading 'textstem' package:'sylly' 'koRpus' 'koRpus.lang.en'

# install.packages('rJava') 
## required for loading 'KoNLP' package

# install.packages('KoNLP') 
## IF NOT INSTALLED : trouble shooting here (https://github.com/haven-jeon/KoNLP)

# install.packages('memoise')

# install.packages('RColorBrewer')

# install.packages('wordcloud2')


## ATTACH packages
library(plyr);library(dplyr);
library(NLP);library(tm);
library(sylly);library(koRpus);library(koRpus.lang.en);library(textstem);
library(rJava);library(KoNLP);
library(memoise);
library(RColorBrewer);library(wordcloud2);

## READ csv data files, THEN GET dataframes 'corona', 'covid'
corona <- read.csv('articles_search_coronavirus.csv')
covid <- read.csv('articles_search_covid-19.csv')

## ADD 'condition' values of each dataframe
corona$condition <- 'corona'
covid$condition <- 'covid'

## SHOW data info
'corona';str(corona)
'covid';str(covid)

## MERGE 'corona', 'covid' dataframes, THEN GET new raw dataframe 'rawdf'
rawdf <- rbind(corona, covid)

## COMPUTE N/As in the dataframe
colSums(is.na(rawdf)) # if there is no N/A, it is well combined.

## GET 'month', 'day' data FROM data 'date'
rawdf$month <- rawdf$date %>% substr(5, 6)
rawdf$day <- rawdf$date %>% substr(7, 8)

## SELECT data FROM raw dataframe 'rawdf', THEN GET new dataframe 'df'
## needed data:  month, day(just in case), title, text, date (just in case)
df <- rawdf %>% dplyr::select(month, day, title, text, date)

## SET data labels
colnames(df) <- c('Month', 'Day', 'Title', 'Text', 'Date')

## MERGE 'Title', 'Text' data, THEN SET data type AS character, THEN GET data 'Article' 
df$Article <- paste(df$Title, df$Text) %>% as.character()

## WRITE the dataframe 'df' AS csv file
write.csv(df, 'data.csv', row.names = FALSE)

## READ csv data files, THEN GET dataframes 'data'
data <- read.csv('data.csv')

## SET data type of data in dataframe AS character
data$Article <- data$Article %>% as.character()
data$Title <- data$Title %>% as.character()
data$Text <- data$Text %>% as.character()

## SET variable of data in dataframe
article <- data$Article

## SHOW data info and an example of data
str(data)
data %>% tail(1) %>% t()

## SET uppercase letters to lowercase
lower <- sapply(article, tolower, USE.NAMES = FALSE)

## SHOW an example before lower vs. after lower 
cbind(article, lower) %>% head(1) %>% substr(1,1000)

## REPLACE punctuations (, -.) and numbers WITH space
del_punct <- sapply(lower,
                    function(x) as.character(gsub('[[:punct:][:digit:]]', ' ', x)),
                    USE.NAMES = FALSE)
                
## DEFINE mystopwords to be deleted
## stopwords() in 'tm' package
mystopwords <- c(tm::stopwords('en'), 
            'will', 'can', 'may', 
            'also', 'still', 'yet', 
            'much', 'get', 'say', 
            'one', 'two', 'go') 
## can add other stopwords in the 'mystopwords' vector 
                
## DELETE 'mystopwords'
## removeWord() in 'tm' package
del_stopword <- sapply(del_punct,
                       function(x) tm::removeWords(x, mystopwords),
                       USE.NAMES = FALSE)
                     
## DELETE one-letter words (like a, s ...)
del_oneletter <- sapply(del_stopword,
                        function(x) as.character(gsub('\\b[a-z]{1}\\b', '', x)),
                        USE.NAMES = FALSE)

## DELETE 2 or more spaces 
del_space <- sapply(del_oneletter,
                    function(x) as.character(gsub('\\s+', ' ', x)),
                    USE.NAMES = FALSE)

## COMPUTE the number of characters in each step
cbind(lower, del_punct,del_stopword, del_oneletter, del_space) %>% nchar() %>% colSums()

## SHOW an example of each step (cumulatively applied)
cbind(lower, del_punct,del_stopword, del_oneletter, del_space) %>% head(1) %>% substr(1,700)

## LEMMANTIZE articles
## lemmatize_strings in 'textstem' package
lem <- sapply(del_space,
              textstem::lemmatize_strings,
              USE.NAMES = FALSE)

## SET data AS dataframe
words <- lem %>% as.data.frame()

## SET data label
colnames(words) <- 'Word'

## SET data type of data in dataframe AS character
words$Word <- words$Word %>% as.character()

## COMPUTE the number of characters in each step
cbind(del_space, lem) %>% nchar() %>% colSums()

## SHOW an example before lem vs. after lem
cbind(del_space, lem) %>% head(1) %>% substr(1,1000)

## MERGE 'data', 'words' dataframes, THEN GET new dataframe ''
dataset <- cbind(data, words)

## WRITE the dataframes AS csv files (you can skip)
# write.csv(words, 'words.csv', row.names = FALSE)
# write.csv(dataset, 'dataset.csv', row.names = FALSE)

## READ csv data file, THEN GET same dataframes as above'dataset'
# dataset <- read.csv('dataset.csv')

## SET data AS character
# dataset$Word <- dataset$Word %>% as.character()

## ADD a new column to the dataset
dataset$unique_words <- NA

## FOR each row in rows of dataset
## SPLIT 'Word' data according to spaces THEN GET only unique words
## ADD the unique words TO dataset
## ENDFOR
for (i in 1:nrow(dataset)) {
  row_words <- dataset$Word[i]
  listed_unique_words <- lapply(strsplit(row_words, ' '), unique)
  unique_words <- unlist(listed_unique_words) %>% paste(collapse = ' ')
  dataset$unique_words[i] <- unique_words
}

## COMPUTE the number of characters to compare Word with unique_words
dataset %>% dplyr::select(Word,unique_words) %>% nchar() 

## GROUP dataset BY Month
## THEN MERGE unique_words
## THEN GET dataframe'dataset_monthly'
dataset_monthly <- dataset %>% 
    dplyr::group_by(Month) %>% 
    dplyr::summarise(wordset = paste(unique_words, collapse = ' '))

## SHOW dataset info 
dataset_monthly %>% str()
## COMPUTE 
dataset_monthly$wordset %>% t() %>% nchar() #each month has this amount of words 

## WRITE the dataframes AS csv files (you can skip)
# write.csv(dataset_monthly, 'monthly_words.csv', row.names = F)
## it takes long time since a lot of words are in the dataset

## SPLIT the dataset INTO 5 dataframes (Jan~May)
## corresponding each row (for easier loading)
Jan <- dataset_monthly$wordset[1] 
Feb <- dataset_monthly$wordset[2] 
Mar <- dataset_monthly$wordset[3] 
Apr <- dataset_monthly$wordset[4] 
May <- dataset_monthly$wordset[5]

## WRITE txt files
write(Jan, 'Jan.txt')
write(Feb, 'Feb.txt')
write(Mar, 'Mar.txt')
write(Apr, 'Apr.txt')
write(May, 'May.txt')

## READ txt data file, THEN GET same dataset as above (Jan~May)
Jan <- readLines('Jan.txt')
Feb <- readLines('Feb.txt')
Mar <- readLines('Mar.txt')
Apr <- readLines('Apr.txt')
May <- readLines('May.txt')

## EXTRACT noun from datasets (Jan~May), THEN GET (noun1~noun5)
noun1 <- sapply(Jan, extractNoun, USE.NAMES = F)
noun2 <- sapply(Feb, extractNoun, USE.NAMES = F)
noun3 <- sapply(Mar, extractNoun, USE.NAMES = F)
noun4 <- sapply(Apr, extractNoun, USE.NAMES = F)
noun5 <- sapply(May, extractNoun, USE.NAMES = F)
## extractNoun in 'KoNLP' package

## FOR noun in (noun1~noun5)
## REPLACE unnecessary words in noun WITH N/As
## REMOVE N/As in noun
## ENDFOR

## NO1
noun1 <- noun1 %>% gsub('people',NA,.)
noun1 <- noun1 %>% gsub('say',NA,.)
noun1 <- noun1 %>% gsub('one',NA,.)
noun1 <- noun1 %>% gsub('also',NA,.)
noun1 <- noun1 %>% gsub('will',NA,.)
noun1 <- noun1 %>% gsub('day',NA,.)
noun1 <- noun1 %>% gsub('make',NA,.)
noun1 <- noun1 %>% gsub('take',NA,.)
noun1 <- noun1 %>% gsub('two',NA,.)
noun1 <- noun1 %>% gsub('like',NA,.)
noun1 <- noun1 %>% gsub('case',NA,.)
noun1 <- noun1 %>% gsub('go',NA,.)
noun1 <- noun1 %>% gsub('can',NA,.)

## NO2
noun2 <- noun2 %>% gsub('people',NA,.)
noun2 <- noun2 %>% gsub('say',NA,.)
noun2 <- noun2 %>% gsub('one',NA,.)
noun2 <- noun2 %>% gsub('also',NA,.)
noun2 <- noun2 %>% gsub('will',NA,.)
noun2 <- noun2 %>% gsub('day',NA,.)
noun2 <- noun2 %>% gsub('make',NA,.)
noun2 <- noun2 %>% gsub('take',NA,.)
noun2 <- noun2 %>% gsub('two',NA,.)
noun2 <- noun2 %>% gsub('like',NA,.)
noun2 <- noun2 %>% gsub('case',NA,.)
noun2 <- noun2 %>% gsub('go',NA,.)
noun2 <- noun2 %>% gsub('can',NA,.)

## NO3
noun3 <- noun3 %>% gsub('people',NA,.)
noun3 <- noun3 %>% gsub('say',NA,.)
noun3 <- noun3 %>% gsub('one',NA,.)
noun3 <- noun3 %>% gsub('also',NA,.)
noun3 <- noun3 %>% gsub('will',NA,.)
noun3 <- noun3 %>% gsub('day',NA,.)
noun3 <- noun3 %>% gsub('make',NA,.)
noun3 <- noun3 %>% gsub('take',NA,.)
noun3 <- noun3 %>% gsub('two',NA,.)
noun3 <- noun3 %>% gsub('like',NA,.)
noun3 <- noun3 %>% gsub('case',NA,.)
noun3 <- noun3 %>% gsub('go',NA,.)
noun3 <- noun3 %>% gsub('can',NA,.)


## NO4
noun4 <- noun4 %>% gsub('people',NA,.)
noun4 <- noun4 %>% gsub('say',NA,.)
noun4 <- noun4 %>% gsub('one',NA,.)
noun4 <- noun4 %>% gsub('also',NA,.)
noun4 <- noun4 %>% gsub('will',NA,.)
noun4 <- noun4 %>% gsub('day',NA,.)
noun4 <- noun4 %>% gsub('make',NA,.)
noun4 <- noun4 %>% gsub('take',NA,.)
noun4 <- noun4 %>% gsub('two',NA,.)
noun4 <- noun4 %>% gsub('like',NA,.)
noun4 <- noun4 %>% gsub('case',NA,.)
noun4 <- noun4 %>% gsub('go',NA,.)
noun4 <- noun4 %>% gsub('can',NA,.)


## NO5
noun5 <- noun5 %>% gsub('people',NA,.)
noun5 <- noun5 %>% gsub('say',NA,.)
noun5 <- noun5 %>% gsub('one',NA,.)
noun5 <- noun5 %>% gsub('also',NA,.)
noun5 <- noun5 %>% gsub('will',NA,.)
noun5 <- noun5 %>% gsub('day',NA,.)
noun5 <- noun5 %>% gsub('make',NA,.)
noun5 <- noun5 %>% gsub('take',NA,.)
noun5 <- noun5 %>% gsub('two',NA,.)
noun5 <- noun5 %>% gsub('like',NA,.)
noun5 <- noun5 %>% gsub('case',NA,.)
noun5 <- noun5 %>% gsub('go',NA,.)
noun5 <- noun5 %>% gsub('can',NA,.)

noun1 <- na.omit(noun1)
noun2 <- na.omit(noun2)
noun3 <- na.omit(noun3)
noun4 <- na.omit(noun4)
noun5 <- na.omit(noun5)

## GET tables to count the nouns
count_jan <- table(noun1) %>% sort(decreasing = T)
count_feb <- table(noun2) %>% sort(decreasing = T)
count_mar <- table(noun3) %>% sort(decreasing = T)
count_apr <- table(noun4) %>% sort(decreasing = T)
count_may <- table(noun5) %>% sort(decreasing = T)

## Word count for the entire period, Top 100
count_table <- cbind(count_jan, count_feb, count_mar, count_apr, count_may)
count_table %>% head()
count_all <- rowSums(count_table) %>% as.table()
rowSums(count_table) %>% head(100)

## SET variable 'palette' for argument 'colors'
## brewer.pal() in 'RColorBrewer' package
palette <- brewer.pal(8, 'Set2')

## GET monthly wordclouds 
## wordcloud2() in 'wordcloud2' package

## 1(Jan)
wordcloud2(data = count_jan, size=0.7, color = palette)

## 2(Feb)
wordcloud2(data = count_feb, size=0.7, color = palette)

## 3(Mar)
wordcloud2(data = count_mar, size=0.7, color = palette)

## 4(Apr)
wordcloud2(data = count_apr, size=0.7, color = palette)

## 5(May)
wordcloud2(data = count_may, size=0.7, color = palette)

## ALL(Jun~May)
wordcloud2(data = count_all, size=0.7, color = palette)

## GET monthly barplot, top 20 words 
par(mar=c(4,7,4,4))
barplot(count_jan[1:20], col=palette, las=2, log="x", horiz=T, xlab = "count", main = "Top 20 words in January")
barplot(count_feb[1:20], col=palette, las=2, log="x", horiz=T, xlab = "count", main = "Top 20 words in February")
barplot(count_mar[1:20], col=palette, las=2, log="x", horiz=T, xlab = "count", main = "Top 20 words in March")
barplot(count_apr[1:20], col=palette, las=2, log="x", horiz=T, xlab = "count", main = "Top 20 words in April")
barplot(count_may[1:20], col=palette, las=2, log="x", horiz=T, xlab = "count", main = "Top 20 words in May")
barplot(count_all[1:20], col=palette, las=2, log="x", horiz=T, xlab = "count", main = "Top 20 words")
