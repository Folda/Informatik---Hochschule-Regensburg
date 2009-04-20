Rational add (Rational *a, Rational *b) {
  Rational c = {a->zaehler*b->nenner+b->zaehler*a->nenner, a->nenner*b->nenner};
  assert (a->nenner);
  assert (b->nenner);
  umformen (&c);
  return c;
}

Rational sub (Rational *a, Rational *b) {
  Rational c = {a->zaehler*b->nenner-b->zaehler*a->nenner, a->nenner*b->nenner};
  assert (a->nenner);
  assert (b->nenner);
  umformen (&c);
  return c;
}

Rational mul ( Rational *a,  Rational *b) {
  Rational c = {a->zaehler*b->zaehler, a->nenner*b->nenner};
  assert (a->nenner);
  assert (b->nenner);
  umformen (&c);
  return c;
}

Rational divi ( Rational *a,  Rational *b) {
  Rational c = {a->zaehler*b->nenner, a->nenner*b->zaehler};
  assert (a->nenner);
  assert (b->nenner);
  umformen (&c);
  return c;
}
