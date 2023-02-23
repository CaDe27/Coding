vector < PT > ConvexHull(vector < PT > &P){
  sort(P.begin(), P.end());
  vector < PT > U, L;
  for(int i = 0; i < P.size(); i++){
    while(L.size() > 1 && cross(L[L.size()-1]-L[L.size()-2], P[i]-L[L.size()-2]) > 0)
      L.pop_back();
    L.push_back(P[i]);
  }
  if(L.size() > 1) L.pop_back();
  for(int i = P.size()-1; i >= 0; i--){
    while(U.size() > 1 && cross(U[U.size()-1]-U[U.size()-2], P[i]-U[U.size()-2]) > 0)
      U.pop_back();
    U.push_back(P[i]);
  }
  if(U.size() > 1) U.pop_back();
  L.insert(L.end(), U.begin(), U.end());
  return L;
}
