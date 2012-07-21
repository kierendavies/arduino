void setup() {
  Mouse.begin();
}

void loop() {
  if (Mouse.isPressed()) {
    Mouse.move(random(100), random(100), 0);
  }
}
