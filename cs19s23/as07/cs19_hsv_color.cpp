#include "cs19_hsv_color.h"
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

namespace cs19 {

HsvColor::HsvColor(float hue, float saturation, float value) {
  if (hue >= 0 && hue <= 360.0) {
    hue2 = hue;
  } else {
    throw std::domain_error("Hue input out of range. [0.0 - 360.0]");
  }
  if (saturation >= 0 && saturation <= 1.0) {
    sat = saturation;
  } else {
    throw std::domain_error("Saturation input out of range. [0.0 - 1.0]");
  }
  if (value >= 0 && value <= 1.0) {
    val = value;
  } else {
    throw std::domain_error("Value input out of range. [0.0 - 1.0]");
  }
  HSV_RBG_convert();
}

HsvColor HsvColor::operator~() const {
  float obj_hue = hue2;
  if (obj_hue <= 360 && obj_hue > 180) {
    obj_hue -= 180;
  } else {
    obj_hue += 180;
  }

  return cs19::HsvColor(obj_hue, sat, val);
}

HsvColor HsvColor::operator|(const HsvColor &that) const {
  float avg_hue = (this->hue2 + that.hue2) / 2;
  float avg_sat = (this->sat + that.sat) / 2;
  float avg_val = (this->val + that.val) / 2;

  return cs19::HsvColor(avg_hue, avg_sat, avg_val);
}

HsvColor HsvColor::grayscale() const {
  return cs19::HsvColor(hue2, 0, val);
}

// The following code was yoinked from
// https://www.codespeedy.com/hsv-to-rgb-in-cpp/
void HsvColor::HSV_RBG_convert() {
  float c = sat * val;
  float h_ = hue2 / 60;
  float x = c * (1 - std::abs((fmod(h_, 2) - 1)));
  float m = val - c;
  float r = 0;
  float g = 0;
  float b = 0;

  if (hue2 >= 0 && hue2 < 60) {
    r = c, g = x, b = 0;
  } else if (hue2 >= 60 && hue2 < 120) {
    r = x, g = c, b = 0;
  } else if (hue2 >= 120 && hue2 < 180) {
    r = 0, g = c, b = x;
  } else if (hue2 >= 180 && hue2 < 240) {
    r = 0, g = x, b = c;
  } else if (hue2 >= 240 && hue2 < 300) {
    r = x, g = 0, b = c;
  } else if (hue2 >= 300 && hue2 < 360) {
    r = c, g = 0, b = x;
  }

  R = std::round((r + m) * 255);
  G = std::round((g + m) * 255);
  B = std::round((b + m) * 255);
}

std::string HsvColor::to_rgb_string() const {
  std::ostringstream os;
  os << "rgb(" << R << "," << G << "," << B << ")";
  return os.str();
}

std::string HsvColor::to_hex_string() const {
  std::ostringstream os;
  os << "#" << std::hex << std::setw(2) << std::setfill('0') << R;
  os << std::hex << std::setw(2) << std::setfill('0') << G;
  os << std::hex << std::setw(2) << std::setfill('0') << B;
  std::string hex_str = os.str();
  return hex_str;
}

float HsvColor::hue() const {
  return hue2;
}

float HsvColor::value() const {
  return val;
}

float HsvColor::saturation() const {
  return sat;
}

int HsvColor::red() const {
  return R;
}

int HsvColor::green() const {
  return G;
}

int HsvColor::blue() const {
  return B;
}
}  // namespace cs19