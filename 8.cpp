class NumberContainers {
    public:
        unordered_map<int,int>i2n;
        unordered_map<int,set<int>>n2i;
    
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            if(i2n.count(index)){
                int prev=i2n[index];
                n2i[prev].erase(index);
                if(n2i[prev].empty()){
                    n2i.erase(prev);
                }
            }    
            i2n[index]=number;
            n2i[number].insert(index);
        }
        
        int find(int number) {
            if(n2i.count(number)){
                return *n2i[number].begin();
            }
            return -1;
        }
    };