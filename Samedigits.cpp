bool samedigits(int value) {
  const int digit = value % 10;
  while (value) {
    if (value % 10 != digit) return false;
    value /= 10;
  }
  return true;
}
