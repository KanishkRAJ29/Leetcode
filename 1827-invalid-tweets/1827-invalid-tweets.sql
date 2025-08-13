# Write your MySQL query statement below
SELECT tweet_id from Tweets where  CHAR_LENGTH(content)>15

/* lenght returs the length of string while char_length returns number of characters used
SELECT LENGTH('€')  # is equal to 3
SELECT CHAR_LENGTH('€') # is equal to 1

LENGTH() returns the length of the string measured in bytes.
CHAR_LENGTH() returns the length of the string measured in characters.
*/