struct SegmentTree
{
  ll n;
  vll v;
  SegmentTree(ll size)
  {
    n=4*size+1;
    v.resize(n,0);
  }
  void build(ll ar[],ll ipos,ll fpos,ll pos=1)
  {
    if(ipos>fpos)
    return ;
    if(ipos==fpos)
    v[pos]=ar[ipos];
    else
    {
    ll mid=(ipos+fpos)/2;
    build(ar,ipos,mid,pos*2);
    build(ar,mid+1,fpos,pos*2+1);
    v[pos]=v[pos*2]+v[pos*2+1];
    }
  }
  void update(ll index,ll val,ll ipos,ll fpos,ll pos=1)
  {
    if(ipos>fpos)
    return ;
    if(ipos==fpos)
    v[pos]+=val;
    else
    {
      v[pos]+=val;
      ll mid=(ipos+fpos)/2;
      if(mid>=index)
      update(index,val,ipos,mid,pos*2);
      else
      update(index,val,mid+1,fpos,pos*2+1);
    }
  }
  ll get_sum(ll l,ll r,ll ipos,ll fpos,ll pos=1)
  {
    if(ipos>fpos)
    return 0;
    if(l>r)
    return 0;
    ll mid=(ipos+fpos)/2;
    if((l==ipos)&&(r==fpos))
    return v[pos];
    else return get_sum(l,min(mid,r),ipos,mid,pos*2)+get_sum(max(mid+1,l),r,mid+1,fpos,pos*2+1);
  }
};