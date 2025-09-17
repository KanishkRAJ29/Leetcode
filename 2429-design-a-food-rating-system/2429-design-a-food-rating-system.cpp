class FoodRatings {
public:
    unordered_map<string, map<int, set<string>>> mp;
    unordered_map<string, int> foodmap;
    unordered_map<string, string> cusinemap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodmap[foods[i]] = ratings[i];
            cusinemap[foods[i]] = cuisines[i];
            mp[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodmap[food];
        string cus = cusinemap[food];

        // erase from old rating set
        mp[cus][oldRating].erase(food);
        if (mp[cus][oldRating].empty()) {
            mp[cus].erase(oldRating);
        }

        // insert into new rating set
        mp[cus][newRating].insert(food);

        // update food rating
        foodmap[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = mp[cuisine].rbegin();   // max rating
        return *it->second.begin();       // lexicographically smallest food
    }
};
