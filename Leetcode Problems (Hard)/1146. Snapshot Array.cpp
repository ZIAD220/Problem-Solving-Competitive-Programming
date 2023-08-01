class SnapshotArray {
public:

    vector<vector<pair<int, int>>> arr;

    int curSnap;

    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>> (length, vector<pair<int, int>> (1, {0, 0}));
        curSnap = 0;
    }
    
    void set(int index, int val) {
        // Finding if we've already modified in this current snapshot.
        auto it = lower_bound(arr[index].begin(), arr[index].end(), make_pair(curSnap, -1));
        
        // If yes, we modfiy the value. Otherwise, we set the new value.
        if (it != arr[index].end() && it->first == curSnap)
            it->second = val;
        else
            arr[index].emplace_back(curSnap, val);
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, (int)1e9));
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */