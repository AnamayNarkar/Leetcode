#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
  unordered_map<int, set<string>> movieMapping; // main
  unordered_map<string, int> movieAndShopToPrice;
  int count;
  set<string> reportSet;

  vector<int> splitStrToInts(const string &s) {
    vector<int> res;
    string token;
    stringstream ss(s);
    while (getline(ss, token, ';')) {
      res.push_back(stoi(token));
    }
    return res;
  }

  string padNumber(int x, int width = 6) {
    stringstream ss;
    ss << setw(width) << setfill('0') << x;
    return ss.str();
  }

public:
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    this->count = n;
    for (vector<int> &vec : entries) {
      this->movieMapping[vec[1]].insert(padNumber(vec[2]) + ";" +
                                        padNumber(vec[0]));
      this->movieAndShopToPrice[padNumber(vec[1]) + ";" + padNumber(vec[0])] =
          vec[2];
    }
  }

  vector<int> search(int movie) {
    vector<int> vec;
    for (string str : this->movieMapping[movie]) {
      int delimiter = str.find(";");
      string shopIdStr = str.substr(delimiter + 1);
      int shopId = stoi(shopIdStr);
      vec.push_back(shopId);
      if (vec.size() == 5)
        break;
    }
    return vec;
  }

  void rent(int shop, int movie) {
    this->movieMapping[movie].erase(
        padNumber(this->movieAndShopToPrice[padNumber(movie) + ";" +
                                            padNumber(shop)]) +
        ";" + padNumber(shop));
    this->reportSet.insert(
        padNumber(this->movieAndShopToPrice[padNumber(movie) + ";" +
                                            padNumber(shop)]) +
        ";" + padNumber(shop) + ";" + padNumber(movie));
  }

  void drop(int shop, int movie) {
    this->movieMapping[movie].insert(
        padNumber(this->movieAndShopToPrice[padNumber(movie) + ";" +
                                            padNumber(shop)]) +
        ";" + padNumber(shop));
    this->reportSet.erase(
        padNumber(this->movieAndShopToPrice[padNumber(movie) + ";" +
                                            padNumber(shop)]) +
        ";" + padNumber(shop) + ";" + padNumber(movie));
  }

  vector<vector<int>> report() {
    vector<vector<int>> finalAns;
    for (string str : this->reportSet) {
      vector<int> tmp = splitStrToInts(str);
      finalAns.push_back({tmp[1], tmp[2]});
      if (finalAns.size() == 5)
        break;
    }
    return finalAns;
  }
};

// without string manipulation using sets and tupes for sorting instead of
// string padding which adds overhead

class MovieRentingSystem {
private:
  unordered_map<int, set<pair<int, int>>> movieMapping;
  map<pair<int, int>, int> movieAndShopToPrice;
  set<tuple<int, int, int>> reportSet;

public:
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    for (const auto &entry : entries) {
      int shop = entry[0];
      int movie = entry[1];
      int price = entry[2];
      movieMapping[movie].insert({price, shop});
      movieAndShopToPrice[{shop, movie}] = price;
    }
  }

  vector<int> search(int movie) {
    vector<int> result;
    for (const auto &p : movieMapping[movie]) {
      result.push_back(p.second);
      if (result.size() == 5)
        break;
    }
    return result;
  }

  void rent(int shop, int movie) {
    int price = movieAndShopToPrice.at({shop, movie});
    movieMapping[movie].erase({price, shop});
    reportSet.insert({price, shop, movie});
  }

  void drop(int shop, int movie) {
    int price = movieAndShopToPrice.at({shop, movie});
    movieMapping[movie].insert({price, shop});
    reportSet.erase({price, shop, movie});
  }

  vector<vector<int>> report() {
    vector<vector<int>> finalAns;
    for (const auto &t : reportSet) {
      finalAns.push_back({get<1>(t), get<2>(t)});
      if (finalAns.size() == 5)
        break;
    }
    return finalAns;
  }
};
