class Solution {
public:
    string upLock(string str, int j){
        if(str[j] == '9'){
            str[j] = '0';
        }else str[j]++;
        return str;
    }

    string downLock(string str, int j){
        if(str[j] == '0'){
            str[j] = '9';
        }else str[j]--;
        return str;
    }

    int openLock(vector<string>& deadends, string target) {
        set<string> deads;
        for(string dead : deadends){
            deads.insert(dead);
        }

        set<string> visited;
        queue<string> q;

        int step = 0;

        q.push("0000");
        visited.insert("0000");

        while(!q.empty()){

            int sz = q.size();

            for(int i = 0; i < sz; ++i){
                string cur = q.front();
                q.pop();
                if(deads.find(cur) != deads.end())
                    continue;
                if(cur == target){
                    return step;
                }

                for(int j = 0; j < 4; ++j){
                    string up = upLock(cur, j);
                    if(visited.find(up) == visited.end()){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = downLock(cur, j);
                    if(visited.find(down) == visited.end()){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;

        }

        return -1;

    }
};