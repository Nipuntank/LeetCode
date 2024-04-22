class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>map(deadends.begin(),deadends.end());
        if(map.count("0000"))
        {
            return -1;
        }
        queue<pair<string,int>>q;
        unordered_set<string>vis;
        q.push({"0000",0});
        vis.insert("0000");
        while(!q.empty())
        {
            string node=q.front().first;
            int step=q.front().second;
            q.pop();
            if(node==target)
            {
                return step;
            }
            for(int i=0;i<4;i++)
            {
                for(int delta:{-1,1})
                {
                    int newDigit=(node[i]-'0'+delta+10)%10;
                    string newNode=node;
                    newNode[i]='0'+newDigit;
                    
                    if(vis.find(newNode)==vis.end() && map.find(newNode)==map.end() )
                    {
                        q.push({newNode,step+1});
                        vis.insert(newNode);
                    }
                }
            }
        }
        return -1;
    }
};