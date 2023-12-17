class FoodRatings {
public:
    vector<string> foods, cuisines;
    vector<int> ratings;
    unordered_map<string,int> foodMap;
    unordered_map<string,set<pair<int,int>>> cusMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->foods = vector<string>(foods);
        this->cuisines = vector<string>(cuisines);
        this->ratings = vector<int>(ratings);
        int n = foods.size();
        for(int i = 0 ; i < n ; i++){
            foodMap[foods[i]] = i;
        }
        for(int i = 0 ; i < n ; i++){
            cusMap[cuisines[i]].insert({ratings[i], i});
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = foodMap[food];
        int oldRating = ratings[idx];
        cusMap[cuisines[idx]].erase({oldRating, idx});
        ratings[idx] = newRating;
        cusMap[cuisines[idx]].insert({newRating, idx});
    }
    
    string highestRated(string cuisine) {
    auto p = cusMap[cuisine].rbegin();
    int topRating = p->first;
    int prevIdx = p->second;

        while (p != cusMap[cuisine].rend() && p->first == topRating) {
            if (foods[prevIdx] > foods[p->second]) {
                prevIdx = p->second;
            }
            p++;
        }

        return foods[prevIdx];
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */