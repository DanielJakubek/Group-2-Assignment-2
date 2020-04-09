from twitter_scraper import get_tweets

tweets = list(get_tweets('MuseeLouvre', pages=1))
print(tweets[0]['text'])

f = open("tweet.txt", "w")
f.write(tweets[0]['text'])

