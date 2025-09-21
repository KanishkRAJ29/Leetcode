
class MovieRentingSystem {
    int shops;
    map<pair<int,int>,int>movieShopToPrice;
    unordered_map<int,set<pair<int,int>>>movieToShop;
    set<pair<int,pair<int,int>>>rentedList;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this -> shops = n;
        for(int i = 0 ; i < entries.size() ; i++){
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            movieShopToPrice[{movie,shop}] = price;
            movieToShop[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>cheapestShops;
        for(auto [price , shop] : movieToShop[movie]){
            cheapestShops.push_back(shop);
            if(cheapestShops.size() == 5) break;
        }
        return cheapestShops;
    }
    
    void rent(int shop, int movie) {
        int price = movieShopToPrice[{movie,shop}];
        movieToShop[movie].erase({price,shop});
        rentedList.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        int price = movieShopToPrice[{movie,shop}];
        movieToShop[movie].insert({price,shop});
        rentedList.erase({price,{shop,movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>cheapestShopsRented;
        for(auto [price,x] : rentedList){
            auto [shop,movie] = x;
            cheapestShopsRented.push_back({shop,movie});
            if(cheapestShopsRented.size() == 5) break;
        }
        return cheapestShopsRented;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */