class SGMNT{
    private:
        vector<long long>seg;long long sz,skip=0; // change skip value
        long long merge(long long a,long long b)
        {
            return a+b; // change operation
        }
        void update(long long l,long long r,long long node,long long idx,long long val)
        {
            if(l==r)
            {
                seg[node]=val;
                return;
            }
            long long mid=(l+r)>>1;
            if(mid<idx)
            {
                update(mid+1,r,2*node+2,idx,val);
            }
            else
            {
                update(l,mid,2*node+1,idx,val);
            }
            seg[node]=merge(seg[2*node+1],seg[2*node+2]);
        }
        long long query(long long l,long long r,long long node,long long lx,long long rx)
        {
            if(l>rx||r<lx)return skip;
            if(l>=lx&&r<=rx)return seg[node];
            long long mid=(l+r)>>1;
            long long a=query(l,mid,2*node+1,lx,rx);
            long long b=query(mid+1,r,2*node+2,lx,rx);
            return merge(a,b);
        }
    public:
        SGMNT(){}
        SGMNT(long long n)
        {
            sz=1;
            while(sz<=n)sz<<=1;
            seg=vector<long long>(sz<<1,skip);
        }
        void update(long long idx,long long val) // zero-based
        {
            update(0,sz-1,0,idx,val);
        }
        long long query(long long l,long long r) // zero-based
        {
            return query(0,sz-1,0,l,r);
        }
};