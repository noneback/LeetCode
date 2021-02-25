class SnapshotArray {
private:
    int snap_id = 0;
    vector<vector<int>> data;
public:
    SnapshotArray(int length) {
        for (int i = 0;i < length;i++) {
            vector<int> ele;
            ele.push_back(0);
            data.push_back(ele);
        }
    }
    
    void set(int index, int val) {
        if (snap_id < data[index].size()) data[index][snap_id] = val;
        else {
            while (data[index].size() <= snap_id) {
                int t = data[index][data[index].size() - 1];
                data[index].push_back(t);
            }
            data[index][snap_id] = val;
        }
       
    }
    
    int snap() {
        snap_id++;
        return snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        while (data[index].size() <= snap_id) {
            int t = data[index][data[index].size() - 1];
            data[index].push_back(t);
        }
        return  data[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
