int equals ( Rational *a,  Rational *b) {
  return a->zaehler*b->nenner == a->nenner*b->zaehler;
}
