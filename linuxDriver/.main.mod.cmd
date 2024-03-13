cmd_/home/krayt/relearning_C/linuxDriver/main.mod := printf '%s\n'   main.o | awk '!x[$$0]++ { print("/home/krayt/relearning_C/linuxDriver/"$$0) }' > /home/krayt/relearning_C/linuxDriver/main.mod
