class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > paths;
        int target=-1, source=-1,len=beginWord.size();
        if(find(wordList.begin(), wordList.end(),beginWord)==wordList.end()) wordList.push_back(beginWord);
        int s = wordList.size();
        
        unordered_map<string, vector<int> >  neighbors={};
        for(int i=0;i<s;i++){ //construct neighbors, replace each character separately in the word with '*' to match all alphs
            for(int j=0;j<len;j++){
                string str(wordList[i]);
                string newstr = str.replace(j,1,"*");
                neighbors[newstr].push_back(i);
            }
            if(wordList[i] == endWord) target = i;
            if(wordList[i] == beginWord) source = i;
        }
        if(target<0) return paths; // dict does not contain end word
        
        // use bi-direction breadth first search 
        vector<int> begfront={source};
        vector<int> endfront={target}, visited = {source,target};
        vector<set<int> > traceback(s, set<int>()); // traceback vector
        vector<int> *set1, *set2; // set1 is for forward search, and then look for in set2
        bool forward, connected=false;
        while(begfront.size() && endfront.size()){
            if(begfront.size()<=endfront.size()){ // keep the number of nodes on two frontiers close for optimization
                set1 = &begfront;
                set2 = &endfront;
                forward = true;
            }else{
                set1 = &endfront;
                set2 = &begfront;
                forward = false;
            }
            
            vector<int> inter; // for intemediate nodes
            for(auto i : *set1){
                for(int j=0;j<len;j++){
                    string tmp(wordList[i]);
                    tmp.replace(j,1,"*");
                    for(int n : neighbors[tmp]){
                        if(find(set2->begin(), set2->end(), n)!=set2->end()){ // find a valid path
                            if(forward) traceback[i].insert(n);
                            else traceback[n].insert(i);
                            connected = true;
                            continue;
                        }
                        if(find(visited.begin(), visited.end(), n)!=visited.end()) continue; // nodes already visited, skip
                        inter.push_back(n);
                        if(forward) traceback[i].insert(n);
                        else traceback[n].insert(i);
                    }
                }
            }
            visited.insert(visited.begin(), inter.begin(), inter.end()); // add intermediate nodes to visited set
            swap(*set1, inter);
            if(connected) { // two frontiers meet, stop and start to build the path
                vector<string> path;
                path.push_back(wordList[source]);
                constructPath(traceback, wordList,path,source,target,paths);
                return paths;
            }
        }
        return paths;// cannot find a valid path, return
    }
    
    void constructPath(vector<set<int> >& traceback, vector<string>& wordList, vector<string>& path, int node, int target, vector<vector<string> >& paths){ // build the path
        if(traceback[node].size()==0 && node==target){
            paths.push_back(path);
            return;
        }
        for(int i:traceback[node]){
            path.push_back(wordList[i]);
            constructPath(traceback, wordList, path, i, target,paths);
            path.pop_back();
        }
        
    }
    
};
