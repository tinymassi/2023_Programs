#include <iostream>
#include <string>

#ifndef _CS19_HSV_COLOR_H
#define _CS19_HSV_COLOR_H

namespace cs19 {
class HsvColor {

public:

  HsvColor(float hue, float saturation, float value); // done
  HsvColor operator~() const;                         // done
  HsvColor operator|(const HsvColor &that) const;     // done
  HsvColor grayscale() const;                         // done

  std::string to_hex_string() const; // done
  std::string to_rgb_string() const; // done

  float hue() const;        // done
  float saturation() const; // done
  float value() const;      // done
  int red() const;          // done
  int green() const;        // done
  int blue() const;         // done

private:
  void HSV_RBG_convert();
  float hue2;
  float sat;
  float val;
  int R;
  int G;
  int B;
};

} // namespace cs19

#endif // _CS19_HSV_COLOR_H