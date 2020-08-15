class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty()) return path;
        stringstream ss(path);
        string rlt, tmp;
         while(getline(ss,tmp,'/')) {
            if(tmp=="..") {if(!rlt.empty()) rlt = rlt.substr(0, (int)rlt.rfind("/"));}
            else if(!tmp.empty() && tmp!=".") {rlt += "/" + tmp;}
        }
        return rlt.empty() ? "/" : rlt;
    }
    /*
    string simplifyPath(string path) {
        if(path.empty()) return path;
        vector<string> dirs;
        int pos=0, len = path.size();
        string rlt;
        while(pos<len){
            while(pos<len && path[pos] == '/') pos++;
            if(pos<len){
                string tmp;
                while(pos<len && path[pos]!='/') tmp += path[pos++];
                if(tmp=="..") {if(dirs.size()>0) dirs.pop_back();}
                else if(tmp!=".") dirs.push_back(tmp);
            }
        }
        for(int i=0;i<dirs.size();i++){
            rlt += "/" + dirs[i];
        }
        return rlt.empty() ? "/" : rlt;
    }*/
};