class SegmentTree{
public:
    vector<int>seg;
    SegmentTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,int arr[]){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind,int low,int high,int l,int r){
        if(high<l || r<low)
            return 1e9;
        if(low>=l && high<=r)
            return seg[ind];
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int ind,int low,int high,int index,int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(index<=mid)
            update(2*ind+1,low,mid,index,val);
        else
            update(2*ind+2,mid+1,high,index,val);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
};
