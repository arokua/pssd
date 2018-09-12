class PaternityTest{
    public:
    vector<int> possibleFathers(string child, string mother, vector<string> men){
        vector<char> d;
        vector<int> n;
        int c = 0;
        int matchT = 0;
        vector<int> posG;
        
        for (int i = 0; i < 4; i++){
            if (child[i] != mother[i]){
                d.push_back(child[i]);
                n.push_back(i);
            }
        }
        cout << d[0] <<" " << n[0]<<endl;
        
        for (int i = 0; i < int(men.size()); i++){
            string dadbe = men[i];
            for (int j = 0; j < 4; j++){
                if (c == 0){
                    if (j == n[c] && dadbe[j] == d[c]){
                        matchT++;
                        c++;
                    }
                    
                }else if ( c >= 1){
                    if (j == n[c] && dadbe[j] == d[c]){
                        matchT++;
                        c++;
                    }
                    
                }
                
            }
            
            if (matchT >=1){
                posG.push_back(i);
            }
            matchT = 0;
            c = 0;
        }
        
        return posG;
    }
};