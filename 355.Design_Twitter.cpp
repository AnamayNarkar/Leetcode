#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Design Twitter
//
// Implement a simplified version of Twitter which allows users to post tweets,
// follow/unfollow each other, and view the 10 most recent tweets within their
// own news feed.
//
// Users and tweets are uniquely identified by their IDs (integers).
//
// Implement the following methods:
//
//     Twitter() Initializes the twitter object.
//     void postTweet(int userId, int tweetId) Publish a new tweet with ID
//     tweetId by the user userId. You may assume that each tweetId is unique.
//     List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent
//     tweet IDs in the user's news feed. Each item must be posted by users who
//     the user is following or by the user themself. Tweets IDs should be
//     ordered from most recent to least recent. void follow(int followerId, int
//     followeeId) The user with ID followerId follows the user with ID
//     followeeId. void unfollow(int followerId, int followeeId) The user with
//     ID followerId unfollows the user with ID followeeId.
//
// Example 1:
//
// Input:
// ["Twitter", "postTweet", [1, 10], "postTweet", [2, 20], "getNewsFeed", [1],
// "getNewsFeed", [2], "follow", [1, 2], "getNewsFeed", [1], "getNewsFeed", [2],
// "unfollow", [1, 2], "getNewsFeed", [1]]
//
// Output:
// [null, null, null, [10], [20], null, [20, 10], [20], null, [10]]
//
// Explanation:
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
// twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
// twitter.getNewsFeed(1);   // User 1's news feed should only contain their own
// tweets -> [10]. twitter.getNewsFeed(2);   // User 2's news feed should only
// contain their own tweets -> [20]. twitter.follow(1, 2);     // User 1 follows
// user 2. twitter.getNewsFeed(1);   // User 1's news feed should contain both
// tweets from user 1 and user 2 -> [20, 10]. twitter.getNewsFeed(2);   // User
// 2's news feed should still only contain their own tweets -> [20].
// twitter.unfollow(1, 2);   // User 1 follows user 2.
// twitter.getNewsFeed(1);   // User 1's news feed should only contain their own
// tweets -> [10].
//
// Constraints:
//
//     1 <= userId, followerId, followeeId <= 100
//     0 <= tweetId <= 1000
//

class Twitter {
private:
  int tweetCount;
  unordered_map<int, priority_queue<pair<int, int>>> userIdMappedToTheirTweets;
  unordered_map<int, unordered_set<int>> followingIds;

public:
  Twitter() { this->tweetCount = 0; }

  void postTweet(int userId, int tweetId) {
    if (this->userIdMappedToTheirTweets.find(userId) ==
        this->userIdMappedToTheirTweets.end()) {
      priority_queue<pair<int, int>> pq;
      this->userIdMappedToTheirTweets[userId] = pq;
    }
    this->userIdMappedToTheirTweets[userId].push(
        make_pair(this->tweetCount, tweetId));
    this->tweetCount++;
  }

  vector<int> getNewsFeed(int userId) {

    vector<int> finalFeed;

    // vector<pair<int, int>> forRePushing;
    priority_queue<pair<int, int>> pq;
    priority_queue<pair<int, int>> tempPQ;
    for (auto it = this->followingIds[userId].begin();
         it != this->followingIds[userId].end(); ++it) {
      // while (this->userIdMappedToTheirTweets[tempHead->userId].size() != 0) {
      //   forRePushing.push_back(
      //       this->userIdMappedToTheirTweets[tempHead->userId].top());
      //   pq.push(this->userIdMappedToTheirTweets[tempHead->userId].top());
      //   this->userIdMappedToTheirTweets[tempHead->userId].pop();
      // }
      // while (forRePushing.size() != 0) {
      //   this->userIdMappedToTheirTweets[tempHead->userId].push(
      //       *forRePushing.end());
      //   forRePushing.pop_back();
      // }

      tempPQ = this->userIdMappedToTheirTweets[*it];
      while (!tempPQ.empty()) {
        pq.push(tempPQ.top());
        tempPQ.pop();
      }
    }

    if (userIdMappedToTheirTweets.count(userId)) {
      tempPQ = userIdMappedToTheirTweets[userId];
      while (!tempPQ.empty()) {
        pq.push(tempPQ.top());
        tempPQ.pop();
      }
    }

    while (finalFeed.size() != 10 && !pq.empty()) {
      finalFeed.push_back(pq.top().second);
      pq.pop();
    }
    return finalFeed;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) {
      return;
    }
    this->followingIds[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId) {
      return;
    }
    if (this->followingIds[followerId].find(followeeId) !=
        this->followingIds[followerId].end()) {
      this->followingIds[followerId].erase(
          this->followingIds[followerId].find(followeeId));
    }
  }
};

void printVector(vector<int> &vec) {
  if (vec.empty()) {
    cout << "null vec" << endl;
  } else {
    cout << "[ ";
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "]" << endl;
  }
}

int main() {
  vector<int> ans;
  Twitter tw;
  tw.postTweet(1, 10);
  tw.postTweet(2, 20);
  ans = tw.getNewsFeed(1);
  printVector(ans);
  ans = tw.getNewsFeed(2);
  printVector(ans);
  tw.follow(1, 2);
  ans = tw.getNewsFeed(1);
  printVector(ans);
  ans = tw.getNewsFeed(2);
  printVector(ans);
  tw.unfollow(1, 2);
  ans = tw.getNewsFeed(1);
  printVector(ans);
}
