#ifndef SDN_HEADER_H
#define SDN_HEADER_H
/* Type definition */

//typedef unsigned long long int uint64_t;
//typedef unsigned long int uint32_t;
namespace sdn {

typedef struct {

  char     header_uid [4];
  char     header_version [4];
  uint32_t topic_size;
  uint64_t topic_counter;
  uint64_t send_time;
  uint64_t recv_time;

} Header_t;
//For backward compatibility
#define SDNHeader_t sdn::Header_t
#define sdn_header sdn:Header

} /* namespace sdn */

#endif /* SDN_HEADER_H */
