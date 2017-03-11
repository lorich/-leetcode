// 355. Design Twitter
// https://leetcode.com/problems/design-twitter/
// 

class Twitter {
private:
    int idmaker;
    unordered_map<int, set<int> > mapFollower;
    unordered_map<int, vector<pair<int, int> > > mapTweet;

public:
    /** Initialize your data structure here. */
    Twitter() {
       idmaker=0; 
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        mapTweet[userId].push_back(make_pair(this->idmaker++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        unordered_map<int, int> mapIndex;
        mapIndex[userId] = mapTweet[userId].size()-1;
        for(const auto &val:mapFollower[userId])
        {
            mapIndex[val] = mapTweet[val].size()-1;
        }
        vector<int> vecRes;
        int count=10;
        while(count--)
        {
            int maxId=-1, maxIdUser=0, maxIdTid=0;
            for (const auto &itr : mapIndex)
            {
                if (itr.second >= 0)
                {
                    if(mapTweet[itr.first][itr.second].first > maxId)
                    {
                        maxId = mapTweet[itr.first][itr.second].first;
                        maxIdTid = mapTweet[itr.first][itr.second].second;
                        maxIdUser = itr.first;
                    }
                }
            }
            if (-1 == maxId)
            {
                break;
            }
            vecRes.push_back(maxIdTid);
            mapIndex[maxIdUser]--;
        }
        return vecRes;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        mapFollower[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        mapFollower[followerId].erase(followeeId);
    }
};

/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods: postTweet(userId, tweetId): Compose a new tweet. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. follow(followerId, followeeId): Follower follows a followee. unfollow(followerId, followeeId): Follower unfollows a followee. Example: 
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
 Subscribe to see which companies asked this question. Show Tags Hash Table Heap Design
*/
