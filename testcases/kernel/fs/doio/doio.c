#include "pattern.h"
char		*syserrno(int err);
void		doio(void);
void		doio_delay(void);
char		*format_oflags(int oflags);
char		*format_strat(int strategy);
char		*format_rw(struct io_req *ioreq, int fd, void *buffer,
			int signo, char *pattern, void *iosw);
#ifdef CRAY
char		*format_sds(struct io_req *ioreq, void *buffer, int sds
			char *pattern);
#endif /* CRAY */

int		do_read(struct io_req *req);
int		do_write(struct io_req *req);
int		lock_file_region(char *fname, int fd, int type, int start,
			int nbytes);
#ifdef CRAY
char		*format_listio(struct io_req *ioreq, int lcmd,
			struct listreq *list, int nent, int fd, char *pattern);
#endif /* CRAY */

int		do_listio(struct io_req *req);

#if defined(_CRAY1) || defined(CRAY)
int		do_ssdio(struct io_req *req);
#endif /* defined(_CRAY1) || defined(CRAY) */

char		*fmt_ioreq(struct io_req *ioreq, struct syscall_info *sy,
			int fd);

#ifdef CRAY
struct status	*sy_listio(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
int		listio_mem(struct io_req *req, int offset, int fmstride,
			int *min, int *max);
char		*fmt_listio(struct io_req *req, struct syscall_info *sy,
			int fd, char *addr);
#endif /* CRAY */

#ifdef sgi
struct status	*sy_pread(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
struct status	*sy_pwrite(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
char		*fmt_pread(struct io_req *req, struct syscall_info *sy,
			int fd, char *addr);
#endif	/* sgi */
struct status	*sy_readv(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
struct status	*sy_writev(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
struct status	*sy_rwv(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr, int rw);
char		*fmt_readv(struct io_req *req, struct syscall_info *sy,
			int fd, char *addr);
#endif /* !CRAY */
#ifdef sgi
struct status	*sy_aread(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
struct status	*sy_awrite(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr)
struct status	*sy_arw(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr, int rw);
char		*fmt_aread(struct io_req *req, struct syscall_info *sy,
			int fd, char *addr);
#endif /* sgi */

#ifndef CRAY
struct status	*sy_mmread(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
struct status	*sy_mmwrite(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr);
struct status	*sy_mmrw(struct io_req *req, struct syscall_info *sysc,
			int fd, char *addr, int rw);
char		*fmt_mmrw(struct io_req *req, struct syscall_info *sy, int fd,
			char *addr);
#endif /* !CRAY */

int		do_rw(struct io_req *req);

#ifdef sgi
int		do_fcntl(struct io_req *req);
#endif /* sgi */

#ifndef CRAY
int		do_sync(struct io_req *req);
#endif /* !CRAY */

int		doio_pat_fill(char *addr, int mem_needed, char *Pattern,
			int Pattern_Length, int shift);
char		*doio_pat_check(char *buf, int offset, int length,
			char *pattern, int pattern_length, int patshift);
char		*check_file(char *file, int offset, int length, char *pattern,
			int pattern_length, int patshift, int fsa);
int		doio_fprintf(FILE *stream, char *format, ...);
int		alloc_mem(int nbytes);

#if defined(_CRAY1) || defined(CRAY)
int		alloc_sds(int nbytes);
#endif /* defined(_CRAY1) || defined(CRAY) */

int		alloc_fd(char *file, int oflags);
struct fd_cache	*alloc_fdcache(char *file, int oflags);

#ifdef sgi
void		signal_info(int sig, siginfo_t *info, void *v);
void		cleanup_handler(int sig, siginfo_t *info, void *v);
void		die_handler(int sig, siginfo_t *info, void *v);
void		sigbus_handler(int sig, siginfo_t *info, void *v);
#else	/* !sgi */
void		cleanup_handler(int sig);
void		die_handler(int sig);

#ifndef CRAY
void		sigbus_handler(int sig);
#endif /* !CRAY */
#endif /* sgi */

void		noop_handler(int sig);
void		sigint_handler(int sig);
void		aio_handler(int sig);
void		dump_aio(void);

#ifdef sgi
void		cb_handler(sigval_t val);
#endif /* sgi */

struct aio_info	*aio_slot(int aio_id);
int		aio_register(int fd, int strategy, int sig);
int		aio_unregister(int aio_id);

#ifndef __linux__
int		aio_wait(int aio_id);
#endif /* !__linux__ */

char		*hms(time_t t);
int		aio_done(struct aio_info *ainfo);
void		doio_upanic(int mask);
int		parse_cmdline(int argc, char **argv, char *opts);

#ifndef CRAY
void		parse_memalloc(char *arg);
void		dump_memalloc(void);
#endif /* !CRAY */

void		parse_delay(char *arg);
int		usage(FILE *stream);
void		help(FILE *stream);
main(int argc, char **argv)
doio(void)
doio_delay(void)
format_rw(struct io_req *ioreq, int fd, void *buffer, int signo, char *pattern,
	void *iosw)
format_sds(struct io_req *ioreq, void *buffer, int sds, char *pattern)
do_read(struct io_req *req)
do_write(struct io_req *req)
lock_file_region(char *fname, int fd, int type, int start, int nbytes)
format_listio(struct io_req *ioreq, int lcmd, struct listreq *list,
	int nent, int fd, char *pattern)
do_listio(struct io_req *req)
do_ssdio(struct io_req *req)
do_ssdio(struct io_req *req)
#endif /* CRAY */
sy_listio(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
listio_mem(struct io_req *req, int offset, int fmstride, int *min, int *max)
sy_pread(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_pwrite(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_readv(struct io_req	*req, struct syscall_info *sysc, int fd, char *addr)
sy_writev(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_rwv(struct io_req *req, struct syscall_info *sysc, int fd, char *addr,
	int rw)
sy_aread(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_awrite(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_arw(struct io_req *req, struct syscall_info *sysc, int fd, char *addr,
	int rw)
sy_mmread(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_mmwrite(struct io_req *req, struct syscall_info *sysc, int fd, char *addr)
sy_mmrw(struct io_req *req, struct syscall_info *sysc, int fd, char *addr,
	int rw)
do_rw(struct io_req *req)
do_fcntl(struct io_req *req)
#endif /* sgi */
do_sync(struct io_req *req)
#endif /* !CRAY */
	int shift)
doio_pat_check(char *buf, int offset, int length, char *pattern,
	int pattern_length, int patshift)
check_file(char *file, int offset, int length, char *pattern,
	int pattern_length, int patshift, int fsa)
alloc_mem(int nbytes)
#else /* CRAY */
alloc_mem(int nbytes)
alloc_sds(int nbytes)
alloc_sds(int nbytes)
alloc_fd(char *file, int oflags)
alloc_fdcache(char *file, int oflags)
cleanup_handler(int sig)
die_handler(int sig)
sigbus_handler(int sig)
		cleanup_handler(sig);
noop_handler(int sig)
sigint_handler(int sig)
aio_handler(int sig)
dump_aio(void)
cb_handler(sigval_t val)
aio_slot(int aio_id)
aio_register(int fd, int strategy, int sig)
aio_unregister(int aio_id)
aio_wait(int aio_id)
hms(time_t t)
doio_upanic(int mask)
parse_cmdline(int argc, char **argv, char *opts)
dump_memalloc(void)
usage(FILE *stream)
help(FILE *stream)