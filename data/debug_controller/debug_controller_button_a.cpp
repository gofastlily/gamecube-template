#include "debug_controller_button_a.hpp"


unsigned char debug_controller_button_a_png[] = {
  0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
  0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
  0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x00,
  0x04, 0x67, 0x41, 0x4d, 0x41, 0x00, 0x00, 0xb1, 0x8f, 0x0b, 0xfc, 0x61,
  0x05, 0x00, 0x00, 0x00, 0x20, 0x63, 0x48, 0x52, 0x4d, 0x00, 0x00, 0x7a,
  0x26, 0x00, 0x00, 0x80, 0x84, 0x00, 0x00, 0xfa, 0x00, 0x00, 0x00, 0x80,
  0xe8, 0x00, 0x00, 0x75, 0x30, 0x00, 0x00, 0xea, 0x60, 0x00, 0x00, 0x3a,
  0x98, 0x00, 0x00, 0x17, 0x70, 0x9c, 0xba, 0x51, 0x3c, 0x00, 0x00, 0x00,
  0x84, 0x65, 0x58, 0x49, 0x66, 0x4d, 0x4d, 0x00, 0x2a, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x05, 0x01, 0x12, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x00, 0x01, 0x1a, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x4a, 0x01, 0x1b, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x52, 0x01, 0x28, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x02, 0x00, 0x00, 0x87, 0x69, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x00, 0x00, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00,
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x03, 0xa0, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x00, 0xa0, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x20, 0xa0, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x00, 0x24, 0xa8, 0xf6, 0x25, 0x00, 0x00, 0x00,
  0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x14, 0x4d, 0x00, 0x00, 0x14,
  0x4d, 0x01, 0x94, 0xca, 0x8d, 0x2f, 0x00, 0x00, 0x03, 0x98, 0x69, 0x54,
  0x58, 0x74, 0x58, 0x4d, 0x4c, 0x3a, 0x63, 0x6f, 0x6d, 0x2e, 0x61, 0x64,
  0x6f, 0x62, 0x65, 0x2e, 0x78, 0x6d, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x3c, 0x78, 0x3a, 0x78, 0x6d, 0x70, 0x6d, 0x65, 0x74, 0x61, 0x20, 0x78,
  0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x78, 0x3d, 0x22, 0x61, 0x64, 0x6f, 0x62,
  0x65, 0x3a, 0x6e, 0x73, 0x3a, 0x6d, 0x65, 0x74, 0x61, 0x2f, 0x22, 0x20,
  0x78, 0x3a, 0x78, 0x6d, 0x70, 0x74, 0x6b, 0x3d, 0x22, 0x58, 0x4d, 0x50,
  0x20, 0x43, 0x6f, 0x72, 0x65, 0x20, 0x36, 0x2e, 0x30, 0x2e, 0x30, 0x22,
  0x3e, 0x0a, 0x20, 0x20, 0x20, 0x3c, 0x72, 0x64, 0x66, 0x3a, 0x52, 0x44,
  0x46, 0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x72, 0x64, 0x66, 0x3d,
  0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e,
  0x77, 0x33, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0x31, 0x39, 0x39, 0x39, 0x2f,
  0x30, 0x32, 0x2f, 0x32, 0x32, 0x2d, 0x72, 0x64, 0x66, 0x2d, 0x73, 0x79,
  0x6e, 0x74, 0x61, 0x78, 0x2d, 0x6e, 0x73, 0x23, 0x22, 0x3e, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x72, 0x64, 0x66, 0x3a, 0x44, 0x65,
  0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x72, 0x64,
  0x66, 0x3a, 0x61, 0x62, 0x6f, 0x75, 0x74, 0x3d, 0x22, 0x22, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78,
  0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x74, 0x69, 0x66, 0x66, 0x3d, 0x22, 0x68,
  0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x6e, 0x73, 0x2e, 0x61, 0x64, 0x6f,
  0x62, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x74, 0x69, 0x66, 0x66, 0x2f,
  0x31, 0x2e, 0x30, 0x2f, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a,
  0x65, 0x78, 0x69, 0x66, 0x3d, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f,
  0x2f, 0x6e, 0x73, 0x2e, 0x61, 0x64, 0x6f, 0x62, 0x65, 0x2e, 0x63, 0x6f,
  0x6d, 0x2f, 0x65, 0x78, 0x69, 0x66, 0x2f, 0x31, 0x2e, 0x30, 0x2f, 0x22,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3a, 0x64, 0x63, 0x3d, 0x22, 0x68,
  0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x70, 0x75, 0x72, 0x6c, 0x2e, 0x6f,
  0x72, 0x67, 0x2f, 0x64, 0x63, 0x2f, 0x65, 0x6c, 0x65, 0x6d, 0x65, 0x6e,
  0x74, 0x73, 0x2f, 0x31, 0x2e, 0x31, 0x2f, 0x22, 0x3e, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x74, 0x69, 0x66, 0x66,
  0x3a, 0x59, 0x52, 0x65, 0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e,
  0x3e, 0x31, 0x33, 0x32, 0x3c, 0x2f, 0x74, 0x69, 0x66, 0x66, 0x3a, 0x59,
  0x52, 0x65, 0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x74, 0x69,
  0x66, 0x66, 0x3a, 0x52, 0x65, 0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f,
  0x6e, 0x55, 0x6e, 0x69, 0x74, 0x3e, 0x32, 0x3c, 0x2f, 0x74, 0x69, 0x66,
  0x66, 0x3a, 0x52, 0x65, 0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e,
  0x55, 0x6e, 0x69, 0x74, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x3c, 0x74, 0x69, 0x66, 0x66, 0x3a, 0x58, 0x52, 0x65,
  0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x31, 0x33, 0x32,
  0x3c, 0x2f, 0x74, 0x69, 0x66, 0x66, 0x3a, 0x58, 0x52, 0x65, 0x73, 0x6f,
  0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x74, 0x69, 0x66, 0x66, 0x3a, 0x4f,
  0x72, 0x69, 0x65, 0x6e, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x31,
  0x3c, 0x2f, 0x74, 0x69, 0x66, 0x66, 0x3a, 0x4f, 0x72, 0x69, 0x65, 0x6e,
  0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x65, 0x78, 0x69, 0x66, 0x3a, 0x50,
  0x69, 0x78, 0x65, 0x6c, 0x58, 0x44, 0x69, 0x6d, 0x65, 0x6e, 0x73, 0x69,
  0x6f, 0x6e, 0x3e, 0x32, 0x35, 0x36, 0x3c, 0x2f, 0x65, 0x78, 0x69, 0x66,
  0x3a, 0x50, 0x69, 0x78, 0x65, 0x6c, 0x58, 0x44, 0x69, 0x6d, 0x65, 0x6e,
  0x73, 0x69, 0x6f, 0x6e, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x3c, 0x65, 0x78, 0x69, 0x66, 0x3a, 0x43, 0x6f, 0x6c,
  0x6f, 0x72, 0x53, 0x70, 0x61, 0x63, 0x65, 0x3e, 0x31, 0x3c, 0x2f, 0x65,
  0x78, 0x69, 0x66, 0x3a, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x70, 0x61,
  0x63, 0x65, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x3c, 0x65, 0x78, 0x69, 0x66, 0x3a, 0x50, 0x69, 0x78, 0x65, 0x6c,
  0x59, 0x44, 0x69, 0x6d, 0x65, 0x6e, 0x73, 0x69, 0x6f, 0x6e, 0x3e, 0x32,
  0x35, 0x36, 0x3c, 0x2f, 0x65, 0x78, 0x69, 0x66, 0x3a, 0x50, 0x69, 0x78,
  0x65, 0x6c, 0x59, 0x44, 0x69, 0x6d, 0x65, 0x6e, 0x73, 0x69, 0x6f, 0x6e,
  0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c,
  0x64, 0x63, 0x3a, 0x74, 0x69, 0x74, 0x6c, 0x65, 0x3e, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x72,
  0x64, 0x66, 0x3a, 0x41, 0x6c, 0x74, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c,
  0x72, 0x64, 0x66, 0x3a, 0x6c, 0x69, 0x20, 0x78, 0x6d, 0x6c, 0x3a, 0x6c,
  0x61, 0x6e, 0x67, 0x3d, 0x22, 0x78, 0x2d, 0x64, 0x65, 0x66, 0x61, 0x75,
  0x6c, 0x74, 0x22, 0x3e, 0x42, 0x75, 0x74, 0x74, 0x6f, 0x6e, 0x20, 0x41,
  0x3c, 0x2f, 0x72, 0x64, 0x66, 0x3a, 0x6c, 0x69, 0x3e, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x2f,
  0x72, 0x64, 0x66, 0x3a, 0x41, 0x6c, 0x74, 0x3e, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x2f, 0x64, 0x63, 0x3a, 0x74,
  0x69, 0x74, 0x6c, 0x65, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x3c, 0x2f, 0x72, 0x64, 0x66, 0x3a, 0x44, 0x65, 0x73, 0x63, 0x72, 0x69,
  0x70, 0x74, 0x69, 0x6f, 0x6e, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x3c, 0x2f,
  0x72, 0x64, 0x66, 0x3a, 0x52, 0x44, 0x46, 0x3e, 0x0a, 0x3c, 0x2f, 0x78,
  0x3a, 0x78, 0x6d, 0x70, 0x6d, 0x65, 0x74, 0x61, 0x3e, 0x0a, 0x77, 0x5a,
  0x9c, 0x92, 0x00, 0x00, 0x06, 0x10, 0x49, 0x44, 0x41, 0x54, 0x58, 0x09,
  0xed, 0x96, 0x7b, 0x68, 0x96, 0x55, 0x1c, 0xc7, 0xcf, 0x39, 0xcf, 0xfb,
  0xee, 0xdd, 0xc5, 0x5d, 0x9c, 0x5b, 0x6a, 0x6a, 0xe9, 0xd6, 0xaa, 0x29,
  0x09, 0xd5, 0xca, 0x4c, 0x77, 0x71, 0x33, 0xc3, 0xd0, 0x2c, 0xcd, 0x0a,
  0x42, 0x84, 0x8a, 0xfa, 0x27, 0xb0, 0x30, 0x65, 0x4b, 0xac, 0x97, 0x0a,
  0x36, 0x0b, 0x24, 0x28, 0x2c, 0x2a, 0xba, 0x10, 0x11, 0x64, 0x96, 0x04,
  0x41, 0x86, 0xed, 0xe2, 0x2e, 0x64, 0x65, 0x17, 0xa1, 0x9c, 0x13, 0xab,
  0xa5, 0x4e, 0xd3, 0xa9, 0xb8, 0xfb, 0xf6, 0x3e, 0xcf, 0xf9, 0xf5, 0x39,
  0x4b, 0x61, 0x97, 0x57, 0x1d, 0x41, 0xfe, 0x93, 0xe7, 0xe5, 0xe1, 0x39,
  0xe7, 0x3c, 0xbf, 0xe7, 0xf7, 0xfd, 0xfe, 0x7e, 0xbf, 0xef, 0xef, 0x3c,
  0xaf, 0x52, 0x97, 0xc7, 0xff, 0x3d, 0x03, 0x7a, 0xac, 0x09, 0x98, 0xdb,
  0xf4, 0x54, 0x52, 0x38, 0x16, 0x9e, 0x6e, 0x6c, 0xf2, 0xa1, 0xda, 0x05,
  0xd1, 0x2e, 0xf7, 0x5e, 0x51, 0xdd, 0xfa, 0x7c, 0x4f, 0x99, 0xc2, 0x9a,
  0xe2, 0xaa, 0xb7, 0x58, 0xca, 0x58, 0x7d, 0x0d, 0xb5, 0x1b, 0x33, 0x81,
  0x92, 0x86, 0x8a, 0x47, 0xb4, 0x55, 0x85, 0x5a, 0xcb, 0x17, 0xd6, 0x98,
  0x03, 0x09, 0x5d, 0x03, 0x07, 0x06, 0x92, 0x42, 0xf5, 0x5a, 0xab, 0x14,
  0x25, 0xfa, 0xb1, 0xe2, 0xc2, 0x48, 0x7d, 0x54, 0x47, 0xed, 0x50, 0xe7,
  0x63, 0x99, 0x8f, 0x89, 0x40, 0x59, 0x63, 0xf9, 0x2d, 0x81, 0x55, 0x15,
  0x5a, 0xf4, 0x31, 0x00, 0xbf, 0x13, 0x25, 0x8b, 0xcf, 0x3a, 0xbf, 0x93,
  0xb8, 0x45, 0x7b, 0x26, 0x22, 0x41, 0xf0, 0x81, 0xaf, 0xcc, 0x86, 0xfa,
  0xa2, 0xca, 0x13, 0x63, 0x01, 0x3e, 0x67, 0x73, 0x41, 0x02, 0x8b, 0x76,
  0x3c, 0x9d, 0xd2, 0x9b, 0x94, 0x90, 0x16, 0xd2, 0x76, 0x13, 0x40, 0xb9,
  0x5a, 0xe9, 0xf7, 0xc0, 0x7b, 0x9c, 0x97, 0xbb, 0x94, 0x56, 0xf9, 0xdc,
  0x03, 0xae, 0x49, 0x5a, 0x93, 0x1b, 0x25, 0x7b, 0x6d, 0xa0, 0x0e, 0xeb,
  0x90, 0x7a, 0xbf, 0x66, 0x5e, 0xd5, 0xb6, 0x73, 0x00, 0x17, 0xbb, 0x5f,
  0x90, 0x40, 0x69, 0x5d, 0x79, 0xa9, 0x68, 0x5d, 0xac, 0xb4, 0xac, 0x18,
  0xac, 0xb0, 0x51, 0x29, 0x5a, 0x9b, 0xcd, 0xd6, 0xda, 0x95, 0x5a, 0x54,
  0x9e, 0xd2, 0x3a, 0x11, 0x80, 0x71, 0x5a, 0x89, 0x15, 0xa5, 0x0d, 0x24,
  0xfe, 0x84, 0xe0, 0x7e, 0xa3, 0x74, 0x0b, 0x65, 0x7a, 0xdb, 0x58, 0x9b,
  0x57, 0x3d, 0xbf, 0x72, 0x3b, 0x76, 0xe7, 0xd5, 0x07, 0x2f, 0xc5, 0x1f,
  0x45, 0x75, 0xeb, 0xf2, 0x44, 0xcb, 0x6d, 0x67, 0xd3, 0x9d, 0xa1, 0x0d,
  0x51, 0x8a, 0xee, 0xc2, 0xd3, 0x3a, 0xdc, 0x75, 0x73, 0xff, 0x44, 0x7b,
  0x3a, 0x83, 0xb7, 0x7d, 0xe6, 0x27, 0x44, 0xec, 0x21, 0xe6, 0x53, 0x01,
  0xbf, 0xc6, 0x2a, 0x3d, 0x53, 0x8b, 0x6c, 0x85, 0xf4, 0xf2, 0x95, 0x5b,
  0xef, 0x3f, 0x2f, 0x86, 0x43, 0x8e, 0xfb, 0x30, 0x2a, 0x51, 0x83, 0xa3,
  0x22, 0x9e, 0x97, 0x52, 0xf3, 0x64, 0x1c, 0xd5, 0x8a, 0xc8, 0x74, 0xd6,
  0xbe, 0xb2, 0x02, 0xa0, 0xe4, 0x1a, 0xa3, 0x1f, 0x96, 0xc0, 0xb6, 0x13,
  0x75, 0x9b, 0x52, 0x7a, 0x80, 0xcc, 0x84, 0xb8, 0x7f, 0x48, 0x26, 0x26,
  0x92, 0x91, 0x99, 0xd8, 0xa6, 0x32, 0x4f, 0x6b, 0x9f, 0x9c, 0xbb, 0xa5,
  0xa4, 0xa9, 0xe2, 0x7a, 0xd6, 0x71, 0x47, 0x5c, 0x02, 0x75, 0xf5, 0xfd,
  0x73, 0x95, 0xd1, 0x0f, 0x91, 0xfe, 0xd9, 0x80, 0x7f, 0x4f, 0xbd, 0x67,
  0x28, 0x91, 0xd7, 0x89, 0xca, 0x03, 0xb0, 0x95, 0xba, 0x91, 0x72, 0x49,
  0xe2, 0x99, 0x8f, 0xd7, 0x08, 0x80, 0x29, 0xec, 0x1f, 0x64, 0x7f, 0x0e,
  0xf7, 0x5f, 0xd9, 0xef, 0xc5, 0x16, 0xc9, 0xa8, 0xa9, 0x64, 0x27, 0xdb,
  0xf8, 0xb2, 0xa6, 0xb4, 0x69, 0xc3, 0xad, 0xf1, 0x18, 0x8c, 0x22, 0x50,
  0x52, 0x13, 0x4d, 0x14, 0x65, 0xef, 0x43, 0xf1, 0x37, 0xe1, 0x30, 0x19,
  0x85, 0xcf, 0x27, 0xfa, 0xdf, 0xa8, 0xe3, 0x24, 0x15, 0x32, 0x99, 0x38,
  0x3f, 0x43, 0xa4, 0x59, 0x38, 0xdb, 0x0f, 0x40, 0x84, 0x7d, 0xe3, 0x4a,
  0xc0, 0xfa, 0x2a, 0x48, 0x65, 0xb0, 0xa7, 0x28, 0x0d, 0x3e, 0x54, 0x07,
  0xef, 0x85, 0x01, 0x28, 0x23, 0xcf, 0x73, 0xc4, 0xf7, 0x1f, 0x9d, 0xd7,
  0xb0, 0x3e, 0x75, 0x24, 0x09, 0xd2, 0x36, 0x62, 0x78, 0x3d, 0x4b, 0xf0,
  0x79, 0x17, 0x91, 0xb4, 0x93, 0xc2, 0x16, 0xe3, 0xe9, 0xc5, 0x46, 0x74,
  0x2a, 0x01, 0xf5, 0xa2, 0x82, 0x55, 0xc4, 0xf5, 0x2a, 0xd9, 0x71, 0x44,
  0x38, 0x8c, 0xa4, 0x05, 0xc0, 0x89, 0x62, 0x55, 0x0f, 0x9d, 0x10, 0x43,
  0x86, 0xbd, 0xc8, 0xf1, 0x3a, 0x3c, 0x9e, 0xfe, 0xa7, 0x2c, 0xcc, 0xb4,
  0xda, 0x0d, 0xb1, 0x12, 0x7c, 0xf9, 0xe1, 0x98, 0x9e, 0xc0, 0x4e, 0xe7,
  0x50, 0xc4, 0x61, 0x19, 0x28, 0xa9, 0x59, 0x8f, 0x88, 0xcc, 0x6a, 0x0c,
  0x72, 0x10, 0x1c, 0x3f, 0x15, 0x09, 0x06, 0x82, 0x37, 0xf0, 0x92, 0x81,
  0x16, 0xa6, 0xa1, 0xfe, 0xd7, 0x20, 0x82, 0x26, 0xe4, 0x73, 0x02, 0x1d,
  0x6f, 0xc2, 0xa1, 0x9b, 0x55, 0x20, 0xbb, 0x99, 0xd7, 0x12, 0x75, 0x0e,
  0xf3, 0x0e, 0xe6, 0xed, 0x90, 0x48, 0x47, 0xf8, 0xb4, 0xa8, 0xc4, 0xc8,
  0x50, 0x3a, 0xb5, 0x68, 0x80, 0x1c, 0x36, 0x32, 0x6b, 0x28, 0xb8, 0x9b,
  0x0f, 0xcb, 0x80, 0x31, 0xe6, 0x5a, 0xea, 0xde, 0xca, 0xfe, 0x09, 0x27,
  0x4f, 0x9c, 0x4d, 0xc7, 0x41, 0x02, 0x62, 0xfb, 0x08, 0x36, 0x47, 0xbd,
  0x48, 0xb8, 0xdc, 0x0e, 0xf8, 0x31, 0x65, 0x15, 0x8e, 0xe5, 0x2f, 0x1b,
  0xf3, 0x23, 0x44, 0xee, 0x0e, 0x25, 0xcf, 0x06, 0xf6, 0x05, 0xee, 0x0f,
  0x98, 0x90, 0x97, 0x65, 0xac, 0x34, 0x05, 0x81, 0xbd, 0x02, 0x52, 0x3d,
  0x94, 0x01, 0x51, 0x52, 0x36, 0xab, 0x6e, 0xe8, 0x0b, 0x0d, 0x3c, 0x87,
  0xcd, 0xb0, 0x31, 0x2c, 0x03, 0xd5, 0xc5, 0x55, 0xd5, 0x54, 0xf4, 0x53,
  0x22, 0xfc, 0x0a, 0x99, 0xed, 0x16, 0x51, 0x2d, 0x44, 0x3e, 0xd7, 0xd5,
  0x5f, 0x2b, 0x73, 0xa3, 0x8d, 0x05, 0xae, 0xd6, 0x47, 0xb9, 0x72, 0x69,
  0xfb, 0xc9, 0xd8, 0xb4, 0x71, 0x02, 0xfd, 0xac, 0x3c, 0xed, 0x1b, 0xad,
  0x37, 0xd2, 0x19, 0x9e, 0xc4, 0x82, 0x2f, 0xa9, 0x7f, 0x26, 0xda, 0x09,
  0xc8, 0x48, 0x3b, 0xed, 0xdb, 0x81, 0x7d, 0x0e, 0xa5, 0xab, 0x8d, 0xf4,
  0x4b, 0x64, 0x18, 0x3a, 0x8b, 0x61, 0x04, 0xdc, 0xc3, 0xea, 0xdb, 0x2b,
  0x6b, 0x88, 0x2e, 0x4c, 0xfa, 0x26, 0x51, 0x3b, 0x11, 0x9f, 0xfe, 0x16,
  0x99, 0x6f, 0xc2, 0xc6, 0x1d, 0xbb, 0x61, 0x14, 0xff, 0x03, 0xa9, 0x39,
  0x26, 0x16, 0x68, 0x63, 0x92, 0x49, 0x75, 0x3e, 0x19, 0x6a, 0x66, 0x1d,
  0x03, 0x24, 0x1f, 0x32, 0x6e, 0xdd, 0xc6, 0xd9, 0x54, 0x4f, 0x06, 0x96,
  0xf2, 0xee, 0x41, 0x02, 0xe9, 0xf7, 0x3c, 0xb3, 0x46, 0x7b, 0x89, 0xaf,
  0x5c, 0x94, 0x40, 0x49, 0xed, 0x06, 0xea, 0xa4, 0x97, 0x70, 0x01, 0xa6,
  0x9c, 0xa0, 0x3e, 0x63, 0x1e, 0x93, 0x80, 0xb8, 0x94, 0xa4, 0x23, 0xa6,
  0xbb, 0x59, 0x23, 0x11, 0xe5, 0x3e, 0x44, 0xd4, 0xda, 0xd0, 0x15, 0x2a,
  0x9b, 0x0e, 0xe9, 0x73, 0x1a, 0xe0, 0x9a, 0x41, 0x00, 0x74, 0x90, 0x5e,
  0x01, 0xf0, 0xbb, 0x5c, 0xa5, 0x84, 0xd1, 0x6d, 0x7d, 0x08, 0x6b, 0xd5,
  0x3d, 0xeb, 0xe3, 0x68, 0xc2, 0x50, 0x12, 0xa3, 0x32, 0xa0, 0x54, 0xc2,
  0x1f, 0x44, 0xfe, 0x2c, 0x29, 0xcc, 0x26, 0xe2, 0x10, 0x35, 0x5e, 0x3d,
  0xd8, 0x56, 0x22, 0x47, 0x58, 0xbb, 0x12, 0xb8, 0xc4, 0x24, 0x03, 0x30,
  0x05, 0xc7, 0xfd, 0x00, 0x24, 0x68, 0xcf, 0xbb, 0x92, 0xf3, 0xf0, 0x14,
  0xdd, 0xd1, 0xc8, 0x95, 0x42, 0xc9, 0x32, 0x11, 0x62, 0x1a, 0xb6, 0xcb,
  0xb8, 0xef, 0x84, 0x68, 0x37, 0x73, 0x3a, 0x49, 0x99, 0xec, 0x6c, 0xd4,
  0x30, 0x64, 0x10, 0x64, 0xfc, 0xb1, 0xa0, 0xbe, 0xfc, 0x1b, 0x28, 0xd3,
  0x0d, 0xc8, 0x32, 0xec, 0x65, 0x29, 0x3f, 0x38, 0xe0, 0xc0, 0x70, 0x3e,
  0x9e, 0x3d, 0x40, 0x54, 0x33, 0x6f, 0xa6, 0x42, 0xc7, 0xb5, 0x56, 0x68,
  0x30, 0x29, 0x46, 0x9f, 0xb1, 0x08, 0x90, 0xee, 0x29, 0x84, 0x48, 0x3a,
  0x1a, 0xe9, 0x83, 0xed, 0x0e, 0x6d, 0xcc, 0x3d, 0xcc, 0xdb, 0x03, 0xb1,
  0xa5, 0xbb, 0x8a, 0x5f, 0xda, 0x37, 0x14, 0x31, 0x2e, 0x01, 0x77, 0x18,
  0xe9, 0x70, 0xef, 0x72, 0x65, 0xcd, 0x11, 0x02, 0x7e, 0x07, 0xe7, 0x9c,
  0x78, 0x92, 0xa5, 0x84, 0x13, 0x5a, 0xb9, 0xe2, 0xeb, 0x1e, 0x88, 0x4c,
  0xc5, 0x91, 0xfb, 0x63, 0xd2, 0x49, 0xbd, 0x11, 0x9a, 0xce, 0x32, 0x61,
  0x6f, 0x02, 0x42, 0xed, 0x65, 0xef, 0x24, 0x51, 0xf7, 0x52, 0xae, 0xc9,
  0xb4, 0xdf, 0x38, 0xb2, 0xa9, 0x6c, 0xcc, 0xae, 0xad, 0x29, 0xac, 0xdc,
  0x3c, 0x14, 0xdc, 0xcd, 0xe3, 0x94, 0x80, 0xa6, 0x5e, 0x10, 0xed, 0x37,
  0x7d, 0x66, 0x07, 0xad, 0x57, 0x80, 0x4d, 0x17, 0x2c, 0xb7, 0x62, 0xca,
  0x69, 0xa8, 0x38, 0xe1, 0xf4, 0x49, 0xee, 0xad, 0x10, 0x42, 0x14, 0x82,
  0x73, 0x3d, 0x11, 0x32, 0xdf, 0x62, 0xd7, 0xcc, 0x7f, 0x82, 0x36, 0x54,
  0x1f, 0xe1, 0x4a, 0x23, 0xf2, 0x33, 0x98, 0x74, 0x9a, 0x84, 0x90, 0xb2,
  0x03, 0x41, 0xa3, 0xf8, 0x91, 0x2d, 0x0e, 0x70, 0xe4, 0x88, 0x4b, 0x00,
  0x23, 0xf9, 0x7a, 0x61, 0xe5, 0x49, 0x52, 0xe9, 0x44, 0xe7, 0x7a, 0xf7,
  0x17, 0x8e, 0x67, 0xb7, 0xbd, 0x07, 0x32, 0xdb, 0x01, 0x28, 0x20, 0xf5,
  0x87, 0xb9, 0x7c, 0x2e, 0x3a, 0x50, 0xaf, 0xe2, 0xe1, 0xd5, 0x36, 0x90,
  0xe7, 0xf9, 0x2a, 0xee, 0xe5, 0x1d, 0xf7, 0xe5, 0xcc, 0x83, 0x61, 0x7b,
  0xd0, 0xef, 0xb7, 0x42, 0xec, 0x09, 0x82, 0xea, 0xc3, 0x66, 0xd4, 0x38,
  0x1f, 0x81, 0x41, 0xc3, 0xe3, 0xc7, 0x12, 0x5f, 0xac, 0x2d, 0xe2, 0x7b,
  0x6e, 0xbc, 0x26, 0x44, 0x07, 0x1f, 0x75, 0x1c, 0xb0, 0x69, 0x1c, 0xbd,
  0x7c, 0xa0, 0xb4, 0x85, 0x88, 0x56, 0x81, 0xdd, 0x87, 0x18, 0x3b, 0x69,
  0xbf, 0x29, 0xac, 0x1f, 0x44, 0x32, 0x0d, 0xb4, 0xa4, 0x2b, 0x4d, 0xb3,
  0x95, 0xd0, 0x32, 0x0e, 0xa4, 0xa5, 0xb5, 0x0b, 0x5e, 0xfe, 0x69, 0x14,
  0xf2, 0xd9, 0x8d, 0xb8, 0x1a, 0x18, 0x69, 0x5c, 0xf2, 0x63, 0x34, 0x23,
  0xd4, 0xd5, 0x97, 0xd9, 0xed, 0xf5, 0x1f, 0x4d, 0xb4, 0x91, 0x8d, 0x24,
  0x63, 0xa6, 0x18, 0x75, 0x1a, 0xfc, 0x7b, 0x01, 0xfb, 0x9d, 0xf2, 0x20,
  0x46, 0xbb, 0x96, 0xc3, 0xe9, 0x0e, 0x74, 0xb0, 0x28, 0x18, 0xf0, 0x1b,
  0x43, 0xc9, 0xf2, 0xe4, 0xce, 0x82, 0x4d, 0xae, 0x45, 0x2f, 0x38, 0xc6,
  0x44, 0x60, 0xa4, 0x87, 0xb2, 0x86, 0x8a, 0x42, 0x72, 0xbc, 0x96, 0x44,
  0x7b, 0x14, 0x66, 0x1b, 0x4e, 0xa6, 0xd5, 0x14, 0x55, 0xb9, 0xa3, 0x58,
  0x2d, 0xac, 0x2f, 0xcf, 0xf1, 0xfd, 0xc4, 0xe3, 0xe7, 0xfe, 0x39, 0x8f,
  0x7c, 0x77, 0xe4, 0xfa, 0x5f, 0x11, 0x70, 0x4e, 0x5c, 0xa7, 0xa8, 0x50,
  0xdf, 0x1a, 0xea, 0x92, 0xd0, 0x91, 0x7c, 0xaa, 0x6a, 0x4f, 0xc1, 0x9b,
  0xb1, 0x91, 0xce, 0x2f, 0xc9, 0xba, 0x6c, 0xd7, 0x33, 0xb3, 0x07, 0xc9,
  0x5c, 0x12, 0xb4, 0xcb, 0x20, 0xff, 0x41, 0x06, 0xfe, 0x06, 0xa5, 0x5d,
  0xb2, 0xb0, 0x95, 0x21, 0xf4, 0x05, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45,
  0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};
unsigned int debug_controller_button_a_png_len = 2766;
