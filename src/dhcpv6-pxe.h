#pragma once

#include <unistd.h>
#include <stddef.h>
#include <libubox/utils.h>
#include <libubox/list.h>

struct ipv6_pxe_entry {
	struct list_head list;	// List head for linking
	uint32_t arch;

	// Ready to send
	struct __attribute__((packed)) {
		uint16_t type;		// In network endianess
		uint16_t len;		// In network endianess, without /0
		char payload[];		// Null-terminated here
	} bootfile_url;
};

struct ipv6_pxe_entry* ipv6_pxe_entry_new(uint32_t arch, const char* url);
void ipv6_pxe_serve_boot_url(uint16_t arch, struct iovec* iov);
void ipv6_pxe_dump(void);
void ipv6_pxe_clear(void);
