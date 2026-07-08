class AuthenticationManager {
public:
    int ttl;
    // token, exp
    unordered_map<string, int> mp;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (mp.count(tokenId) && mp[tokenId] <= currentTime)
            mp.erase(tokenId);
        else if (mp.count(tokenId)) {
            mp[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int c = 0;
        for (auto item: mp) {
            auto [tkn, time] = item;
            if (time > currentTime) {
                c++;
            }
        }
        return c;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */