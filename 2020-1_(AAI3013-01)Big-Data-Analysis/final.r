library(dplyr)
library(ggplot2)

data <- read.csv("COVID19_line_list_data.csv")

df <- as.data.frame(data)
gen <- df %>% group_by(gender) %>% summarise(age) %>% na.omit
death <- df %>% group_by(country) %>% summarise(death) %>% table() %>% as.data.frame()

ggplot(gen, aes(x=gender, y=age))+
    theme_bw()+
    scale_fill_manual(guide=FALSE)+
    ggtitle("Bar plot for count of gender")+
    theme(axis.text.x=element_text(angle=45, vjust=1, size=9,hjust=1))+
    xlab("Gender")+
    ylab("Age")+
    geom_violin()+
    stat_summary(fun.y=mean, geom="point", shape=23, size=2)

ggplot(death,aes(x=country, y=Freq))+
    theme_bw()+
    scale_fill_manual(guide=FALSE)+
    ggtitle("Bar plot for the number of deaths per each country")+
    theme(axis.text.x=element_text(angle=45, vjust=1, size=9,hjust=1))+
    xlab("Country")+
    ylab("Deaths")+
    geom_violin()+
    stat_summary(fun.y=mean, geom="point", shape=23, size=2)
