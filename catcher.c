#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<signal.h>
#include<time.h>
#include<string.h>
#include<unistd.h>



char arr[30][10] = 
{
	"0null","SIGHUP","SIGINT","SIGQUIT","SIGILL","SIGTRAP","SIGABRT",
	"SIGBUS","SIGFPE","9KILL9","SIGUSR1","SIGSEGV","SIGUSR2","SIGPIPE",
	"SIGALRM","SIGTERM","SIGSTKFLT","SIGCHLD","SIGCONT","19SIGSTOP","SIGPROF","SIGWINCH",
	"29null","SIGTSTP","SIGTTIN","SIGTTOU","SIGURG","SIGXCPU","SIGXFSZ",
	"SIGVTALRM"
};
static int xCounter = 0;
static int yCounter = 0;
time_t clk;


void handler(int num) {
	clk = time(NULL);
	yCounter = yCounter + 1;
	printf("%s Caught at %ld\n", arr[num], clk);
	if (num == 15) {
		xCounter = xCounter + 1;
	}
	if (xCounter == 3) {
		fprintf(stderr, "Catcher: Number of Signals caught = %d\n", yCounter);
		exit(0);
	}
	signal(num, handler);
}

int main(int argc, char** argv) {
	int sigArgs = argc - 1;

	for (int i = 0; i <sigArgs; i++) {
		if (strcmp(argv[argc - sigArgs + i], "HUP") == 0) {
			signal(SIGHUP, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "INT") == 0) {
			signal(SIGINT, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "QUIT") == 0) {
			signal(SIGQUIT, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "ILL") == 0) {
			signal(SIGILL, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "TRAP") == 0) {
			signal(SIGTRAP, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "ABRT") == 0) {
			signal(SIGABRT, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "IOT") == 0) {
			signal(SIGIOT, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "BUS") == 0) {
			signal(SIGBUS, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "FPE") == 0) {
			signal(SIGFPE, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "USR1") == 0) {
			signal(SIGUSR1, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "SEGV") == 0) {
			signal(SIGSEGV, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "TERM") == 0) {
			signal(SIGTERM, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "USR2") == 0) {
			signal(SIGUSR2, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "PIPE") == 0) {
			signal(SIGPIPE, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "ALRM") == 0) {
			signal(SIGALRM, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "STKFLT") == 0) {
			signal(SIGSTKFLT, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "CHLD") == 0) {
			signal(SIGCHLD, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "TTIN") == 0) {
			signal(SIGTTIN, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "CONT") == 0) {
			signal(SIGCONT, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "TSTP") == 0) {
			signal(SIGTSTP, handler);
		}
	
		if (strcmp(argv[argc - sigArgs + i], "TTOU") == 0) {
			signal(SIGTTOU, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "XCPU") == 0) {
			signal(SIGXCPU, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "URG") == 0) {
			signal(SIGURG, handler);
		}
		
		if (strcmp(argv[argc - sigArgs + i], "XFSZ") == 0) {
			signal(SIGXFSZ, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "VTALRM") == 0) {
			signal(SIGVTALRM, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "WINCH") == 0) {
			signal(SIGWINCH, handler);
		}
		if (strcmp(argv[argc - sigArgs + i], "PROF") == 0) {
			signal(SIGPROF, handler);
		}
		
	}

	fprintf(stderr, "Catcher Program id:  %d\n", getpid());

	while (1) {
		pause();
	}

	return 0;
}