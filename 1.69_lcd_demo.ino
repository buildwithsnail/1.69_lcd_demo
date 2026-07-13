/*
 * DEBUG-Sketch: Waveshare 1.69" LCD — Arduino Nano ESP32
 *
 * Öffne nach dem Upload den Serial Monitor (115200 Baud)
 * und schau welche Zeile als letzte erscheint.
 *
 * Verdrahtung bleibt gleich:
 *  DIN  → D11 (GPIO47)
 *  CLK  → D13 (GPIO48)
 *  CS   → D10 (GPIO21)
 *  DC   → D9  (GPIO45)
 *  RST  → D8  (GPIO17)
 *  BL   → 3V3 (direkt, kein Pin nötig)
 */

#include <LovyanGFX.hpp>

#define LCD_MOSI  38
#define LCD_SCK   48
#define LCD_CS    21
#define LCD_DC    6
#define LCD_RST   17

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789 _panel;
  lgfx::Bus_SPI      _bus;

public:
  LGFX(void) {
    {
      auto cfg = _bus.config();
      cfg.spi_host   = SPI3_HOST;
      cfg.spi_mode   = 0;
      cfg.freq_write = 10000000;  // 10 MHz – langsam zum Debuggen
      cfg.pin_sclk   = LCD_SCK;
      cfg.pin_mosi   = LCD_MOSI;
      cfg.pin_miso   = -1;
      cfg.pin_dc     = LCD_DC;
      _bus.config(cfg);
      _panel.setBus(&_bus);
    }
    {
      auto cfg = _panel.config();
      cfg.pin_cs       = LCD_CS;
      cfg.pin_rst      = LCD_RST;
      cfg.pin_busy     = -1;
      cfg.panel_width  = 240;
      cfg.panel_height = 280;
      cfg.offset_x     = 0;
      cfg.offset_y     = 20;
      cfg.offset_rotation  = 0;
      cfg.dummy_read_pixel = 8;
      cfg.readable     = false;
      cfg.invert       = true;
      cfg.rgb_order    = false;
      cfg.dlen_16bit   = false;
      cfg.bus_shared   = false;
      _panel.config(cfg);
    }
    setPanel(&_panel);
  }
};

LGFX lcd;

// extern const uint8_t ChatGPTImage[];  // <-- Namen anpassen!

extern const unsigned short pic[];

void setup() {
  lcd.init();
  lcd.setRotation(0);

  lcd.setSwapBytes(true);
  // Bild anzeigen: x=0, y=0, Breite=240, Höhe=280
  // RGB565, 16-bit big-endian
  lcd.pushImage(0, 0, 240, 280, pic);
}
void loop() {}




