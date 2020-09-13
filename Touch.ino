// Touch



#define touch_threshold 40 /* Greater the value, more the sensitivity */

bool touch3detected = false;
bool awake = false;



void setupTouch() {
  touchAttachInterrupt(T3, gotTouch3, touch_threshold);
  esp_sleep_enable_touchpad_wakeup();
}

void loopTouch() {
  if (touch3detected) {
    Serial.println("T3:");
    Serial.println(awake);
    if (awake) {
      deep_sleep();
    }
    awake = true;
  }
}


void gotTouch3(){
 touch3detected = true;
}
