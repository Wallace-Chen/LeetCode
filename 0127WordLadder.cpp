class Solution {
public:
    vector<vector <int> > neighbors;
    /*
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { // A beadth first search on the graph
        int s = wordList.size(), level=1, target=-1, len=beginWord.size();
        wordList.push_back(beginWord);
        
        unordered_map<string, vector<int> >  neighbors={};
        for(int i=0;i<=s;i++){ //construct the graph
            for(int j=0;j<len;j++){
                string str(wordList[i]);
                string newstr = str.replace(j,1,"*");
                neighbors[newstr].push_back(i);
            }
            if(wordList[i] == endWord) target = i;
        }
        //cout << target << endl;
        if(target<0) return 0; // dict does not contain end word
        // use breadth first search 
        vector<int> frontiers={s}, visited = {s};
        while(frontiers.size()>0){
            vector<int> next={};
            level += 1;
            for(int f : frontiers){
                for(int j=0;j<len;j++){
                    string str(wordList[f]);
                    string newstr = str.replace(j,1,"*");
                    for(int n : neighbors[newstr]){
                        if(n==target) return level;
                        if(find(visited.begin(), visited.end(), n)==visited.end()){
                            visited.push_back(n);
                            next.push_back(n);
                        }
                    }
                }
            }
            frontiers = next;
        }
        return 0;// cannot find a valid path, return 0
    }
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { // A beadth first search on the graph, with two ends search, 10X faster
        int s = wordList.size(), level=1, target=-1, len=beginWord.size();
        wordList.push_back(beginWord);
        
        unordered_map<string, vector<int> >  neighbors={};
        for(int i=0;i<=s;i++){ //construct the graph
            for(int j=0;j<len;j++){
                string str(wordList[i]);
                string newstr = str.replace(j,1,"*");
                neighbors[newstr].push_back(i);
            }
            if(wordList[i] == endWord) target = i;
        }
        //cout << target << endl;
        if(target<0) return 0; // dict does not contain end word
        // use breadth first search 
        vector<int> begfront={s};
        vector<int> endfront={target}, visited = {s,target};
        vector<int> *set1, *set2;
        while(begfront.size() && endfront.size()){
            if(begfront.size()<=endfront.size()){ // set1 forward search, set2 to be searched against
                set1 = &begfront;
                set2 = &endfront;
            }else{
                set1 = &endfront;
                set2 = &begfront;
            }
            level ++;
            vector<int> inter;
            for(auto i : *set1){
                for(int j=0;j<len;j++){
                    string tmp(wordList[i]);
                    tmp.replace(j,1,"*");
                    for(int n : neighbors[tmp]){
                        if(find(set2->begin(), set2->end(), n)!=set2->end()) return level;
                        if(find(visited.begin(), visited.end(), n)!=visited.end()) continue;
                        inter.push_back(n);
                        visited.push_back(n);
                    }
                }
            }
            swap(*set1, inter);
        }
        return 0;// cannot find a valid path, return 0
    }
    
};
