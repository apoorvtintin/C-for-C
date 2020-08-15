#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
		int nounfile, verbfile;
		nounfile = open("noun.txt",O_WRONLY);
		verbfile = open("verb.txt",O_WRONLY);
		pid_t pid;

		pid = fork();
		if(pid == 0) {
				pid = fork();
				if(pid == 0) {
						pid = fork();
						if(pid == 0) {
								write(verbfile, "ka", 2);
								write(nounfile, "pi", 2);
								exit(0);
						}
						waitpid(pid, NULL, 0);
						write(verbfile, "chu", 3);
				} else {
						waitpid(pid, NULL, 0);
						write(nounfile, "ka", 2);
				}
		} else {
				write(verbfile, "pi", 2);
				pid = fork();
				if(pid == 0) {
						write(verbfile, "ka", 2);
						write(nounfile, "chu", 3);
						exit(0);
				}
				waitpid(pid, NULL, 0);
				write(verbfile, "chu", 3);
				waitpid(-1, NULL, 0);
		}
		return 0;
}