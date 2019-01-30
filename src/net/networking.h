#ifndef _networking_H_
#define _networking_H_

#include "Arduino.h"

#include "system/configurable.h"

class Networking : public Configurable {
 public:
  Networking(String id, String schema="");
  void setup(std::function<void(bool)> connection_cb);
  String& get_hostname();
  virtual JsonObject& get_configuration(JsonBuffer& buf) override final;
  virtual void set_configuration(const JsonObject& config) override final;

 protected:
  void check_connection();
 private:
  String hostname;
};

#endif