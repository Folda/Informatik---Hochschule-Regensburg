int ggt ( int i,  int j) {
  if (i == 0 || j == 0) 
    return i + j;
  else if (i < 0) {
    if (j < 0)
      return ggt (-i, -j);
    else
      return -ggt (-i, j);
  } else if (j < 0)
    return -ggt (i, -j);
  else if (i < j)     
    return ggt (j-i, i);
  else
    return ggt (i-j, j);
}

void umformen (Rational *r) {
  int ggt_;
  assert (r->nenner);
  if (r->zaehler == 0) {
    r->nenner = 1;
    return;
  }
  ggt_ = ggt(r->zaehler, r->nenner);
  if (ggt_ != 1) {
    r->nenner /= ggt_;
    r->zaehler /= ggt_;
  }
  if (r->nenner < 0) {
    r->nenner = -r->nenner;
    r->zaehler = -r->zaehler;
  }
}
