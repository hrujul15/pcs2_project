#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void) {
  struct fsinfo info;

  if (fsinfo(&info) < 0) {
    printf("fsinfo failed\n");
    exit(1);
  }

  printf("fs_info:\n");
  printf("  files->        %d\n", info.num_files);
  printf("  dirs->  %d\n", info.num_dirs);
  printf("  free blocks->  %d\n", info.free_blocks);
  printf("  inodes used->  %d\n", info.inodes_used);

  exit(0);
}
