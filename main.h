
#define MAXEVENTS	4096
#define MAX_PORCESS	200
#define BUF_SIZE	4096 * 4
#define DOC_ROOT "/var/www/"

#define PORT 8080

struct process_t {
    int sock;
    int status;
    int response_code;
    int fd;
    int read_pos;
    int write_pos;
    char buf[BUF_SIZE];
};

void send_response_header(struct process_t *process);

int setNonblocking(int fd);

struct process_t* find_process_by_sock(int sock);

struct process_t* accept_sock(int listen_sock);

void read_request(struct process_t* process);

void send_response_header(struct process_t *process);

void send_response(struct process_t *process);

void cleanup(struct process_t *process);

void handle_error(struct process_t *process, char* error_string);

void reset_process(struct process_t *process);

int open_file(char *filename);

