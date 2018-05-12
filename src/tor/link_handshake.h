/* link_handshake.h -- generated by by Trunnel v1.5.1.
 * https://gitweb.torproject.org/trunnel.git
 * You probably shouldn't edit this file.
 */
#ifndef TRUNNEL_LINK_HANDSHAKE_H
#define TRUNNEL_LINK_HANDSHAKE_H

#include <stdint.h>
#include "trunnel.h"

#define CERTTYPE_RSA1024_ID_LINK 1
#define CERTTYPE_RSA1024_ID_ID 2
#define CERTTYPE_RSA1024_ID_AUTH 3
#define CERTTYPE_ED_ID_SIGN 4
#define CERTTYPE_ED_SIGN_LINK 5
#define CERTTYPE_ED_SIGN_AUTH 6
#define CERTTYPE_RSA1024_ID_EDID 7
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_AUTH_CHALLENGE_CELL)
struct auth_challenge_cell_st {
  uint8_t challenge[32];
  uint16_t n_methods;
  TRUNNEL_DYNARRAY_HEAD(, uint16_t) methods;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct auth_challenge_cell_st auth_challenge_cell_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_AUTH_CTX)
struct auth_ctx_st {
  uint8_t is_ed;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct auth_ctx_st auth_ctx_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_CERTS_CELL_CERT)
struct certs_cell_cert_st {
  uint8_t cert_type;
  uint16_t cert_len;
  TRUNNEL_DYNARRAY_HEAD(, uint8_t) body;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct certs_cell_cert_st certs_cell_cert_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_RSA_ED_CROSSCERT)
struct rsa_ed_crosscert_st {
  uint8_t ed_key[32];
  uint32_t expiration;
  const uint8_t *end_of_signed;
  uint8_t sig_len;
  TRUNNEL_DYNARRAY_HEAD(, uint8_t) sig;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct rsa_ed_crosscert_st rsa_ed_crosscert_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_AUTH1)
struct auth1_st {
  uint8_t type[8];
  uint8_t cid[32];
  uint8_t sid[32];
  uint8_t u1_cid_ed[32];
  uint8_t u1_sid_ed[32];
  uint8_t slog[32];
  uint8_t clog[32];
  uint8_t scert[32];
  uint8_t tlssecrets[32];
  const uint8_t *end_of_fixed_part;
  uint8_t rand[24];
  const uint8_t *end_of_signed;
  TRUNNEL_DYNARRAY_HEAD(, uint8_t) sig;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct auth1_st auth1_t;
#if !defined(TRUNNEL_OPAQUE) && !defined(TRUNNEL_OPAQUE_CERTS_CELL)
struct certs_cell_st {
  uint8_t n_certs;
  TRUNNEL_DYNARRAY_HEAD(, struct certs_cell_cert_st *) certs;
  uint8_t trunnel_error_code_;
};
#endif
typedef struct certs_cell_st certs_cell_t;
/** Return a newly allocated auth_challenge_cell with all elements set
 * to zero.
 */
auth_challenge_cell_t *auth_challenge_cell_new(void);
/** Release all storage held by the auth_challenge_cell in 'victim'.
 * (Do nothing if 'victim' is NULL.)
 */
void auth_challenge_cell_free(auth_challenge_cell_t *victim);
/** Try to parse a auth_challenge_cell from the buffer in 'input',
 * using up to 'len_in' bytes from the input buffer. On success,
 * return the number of bytes consumed and set *output to the newly
 * allocated auth_challenge_cell_t. On failure, return -2 if the input
 * appears truncated, and -1 if the input is otherwise invalid.
 */
ssize_t auth_challenge_cell_parse(auth_challenge_cell_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * auth_challenge_cell in 'obj'. On failure, return a negative value.
 * Note that this value may be an overestimate, and can even be an
 * underestimate for certain unencodeable objects.
 */
ssize_t auth_challenge_cell_encoded_len(const auth_challenge_cell_t *obj);
/** Try to encode the auth_challenge_cell from 'input' into the buffer
 * at 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t auth_challenge_cell_encode(uint8_t *output, size_t avail, const auth_challenge_cell_t *input);
/** Check whether the internal state of the auth_challenge_cell in
 * 'obj' is consistent. Return NULL if it is, and a short message if
 * it is not.
 */
const char *auth_challenge_cell_check(const auth_challenge_cell_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int auth_challenge_cell_clear_errors(auth_challenge_cell_t *obj);
/** Return the (constant) length of the array holding the challenge
 * field of the auth_challenge_cell_t in 'inp'.
 */
size_t auth_challenge_cell_getlen_challenge(const auth_challenge_cell_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * challenge of the auth_challenge_cell_t in 'inp'.
 */
uint8_t auth_challenge_cell_get_challenge(auth_challenge_cell_t *inp, size_t idx);
/** As auth_challenge_cell_get_challenge, but take and return a const
 * pointer
 */
uint8_t auth_challenge_cell_getconst_challenge(const auth_challenge_cell_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * challenge of the auth_challenge_cell_t in 'inp', so that it will
 * hold the value 'elt'.
 */
int auth_challenge_cell_set_challenge(auth_challenge_cell_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field challenge of 'inp'.
 */
uint8_t * auth_challenge_cell_getarray_challenge(auth_challenge_cell_t *inp);
/** As auth_challenge_cell_get_challenge, but take and return a const
 * pointer
 */
const uint8_t  * auth_challenge_cell_getconstarray_challenge(const auth_challenge_cell_t *inp);
/** Return the value of the n_methods field of the
 * auth_challenge_cell_t in 'inp'
 */
uint16_t auth_challenge_cell_get_n_methods(const auth_challenge_cell_t *inp);
/** Set the value of the n_methods field of the auth_challenge_cell_t
 * in 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int auth_challenge_cell_set_n_methods(auth_challenge_cell_t *inp, uint16_t val);
/** Return the length of the dynamic array holding the methods field
 * of the auth_challenge_cell_t in 'inp'.
 */
size_t auth_challenge_cell_getlen_methods(const auth_challenge_cell_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * methods of the auth_challenge_cell_t in 'inp'.
 */
uint16_t auth_challenge_cell_get_methods(auth_challenge_cell_t *inp, size_t idx);
/** As auth_challenge_cell_get_methods, but take and return a const
 * pointer
 */
uint16_t auth_challenge_cell_getconst_methods(const auth_challenge_cell_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * methods of the auth_challenge_cell_t in 'inp', so that it will hold
 * the value 'elt'.
 */
int auth_challenge_cell_set_methods(auth_challenge_cell_t *inp, size_t idx, uint16_t elt);
/** Append a new element 'elt' to the dynamic array field methods of
 * the auth_challenge_cell_t in 'inp'.
 */
int auth_challenge_cell_add_methods(auth_challenge_cell_t *inp, uint16_t elt);
/** Return a pointer to the variable-length array field methods of
 * 'inp'.
 */
uint16_t * auth_challenge_cell_getarray_methods(auth_challenge_cell_t *inp);
/** As auth_challenge_cell_get_methods, but take and return a const
 * pointer
 */
const uint16_t  * auth_challenge_cell_getconstarray_methods(const auth_challenge_cell_t *inp);
/** Change the length of the variable-length array field methods of
 * 'inp' to 'newlen'.Fill extra elements with 0. Return 0 on success;
 * return -1 and set the error code on 'inp' on failure.
 */
int auth_challenge_cell_setlen_methods(auth_challenge_cell_t *inp, size_t newlen);
/** Return a newly allocated auth_ctx with all elements set to zero.
 */
auth_ctx_t *auth_ctx_new(void);
/** Release all storage held by the auth_ctx in 'victim'. (Do nothing
 * if 'victim' is NULL.)
 */
void auth_ctx_free(auth_ctx_t *victim);
/** Return the value of the is_ed field of the auth_ctx_t in 'inp'
 */
uint8_t auth_ctx_get_is_ed(const auth_ctx_t *inp);
/** Set the value of the is_ed field of the auth_ctx_t in 'inp' to
 * 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int auth_ctx_set_is_ed(auth_ctx_t *inp, uint8_t val);
/** Return a newly allocated certs_cell_cert with all elements set to
 * zero.
 */
certs_cell_cert_t *certs_cell_cert_new(void);
/** Release all storage held by the certs_cell_cert in 'victim'. (Do
 * nothing if 'victim' is NULL.)
 */
void certs_cell_cert_free(certs_cell_cert_t *victim);
/** Try to parse a certs_cell_cert from the buffer in 'input', using
 * up to 'len_in' bytes from the input buffer. On success, return the
 * number of bytes consumed and set *output to the newly allocated
 * certs_cell_cert_t. On failure, return -2 if the input appears
 * truncated, and -1 if the input is otherwise invalid.
 */
ssize_t certs_cell_cert_parse(certs_cell_cert_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * certs_cell_cert in 'obj'. On failure, return a negative value. Note
 * that this value may be an overestimate, and can even be an
 * underestimate for certain unencodeable objects.
 */
ssize_t certs_cell_cert_encoded_len(const certs_cell_cert_t *obj);
/** Try to encode the certs_cell_cert from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t certs_cell_cert_encode(uint8_t *output, size_t avail, const certs_cell_cert_t *input);
/** Check whether the internal state of the certs_cell_cert in 'obj'
 * is consistent. Return NULL if it is, and a short message if it is
 * not.
 */
const char *certs_cell_cert_check(const certs_cell_cert_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int certs_cell_cert_clear_errors(certs_cell_cert_t *obj);
/** Return the value of the cert_type field of the certs_cell_cert_t
 * in 'inp'
 */
uint8_t certs_cell_cert_get_cert_type(const certs_cell_cert_t *inp);
/** Set the value of the cert_type field of the certs_cell_cert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int certs_cell_cert_set_cert_type(certs_cell_cert_t *inp, uint8_t val);
/** Return the value of the cert_len field of the certs_cell_cert_t in
 * 'inp'
 */
uint16_t certs_cell_cert_get_cert_len(const certs_cell_cert_t *inp);
/** Set the value of the cert_len field of the certs_cell_cert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int certs_cell_cert_set_cert_len(certs_cell_cert_t *inp, uint16_t val);
/** Return the length of the dynamic array holding the body field of
 * the certs_cell_cert_t in 'inp'.
 */
size_t certs_cell_cert_getlen_body(const certs_cell_cert_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * body of the certs_cell_cert_t in 'inp'.
 */
uint8_t certs_cell_cert_get_body(certs_cell_cert_t *inp, size_t idx);
/** As certs_cell_cert_get_body, but take and return a const pointer
 */
uint8_t certs_cell_cert_getconst_body(const certs_cell_cert_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * body of the certs_cell_cert_t in 'inp', so that it will hold the
 * value 'elt'.
 */
int certs_cell_cert_set_body(certs_cell_cert_t *inp, size_t idx, uint8_t elt);
/** Append a new element 'elt' to the dynamic array field body of the
 * certs_cell_cert_t in 'inp'.
 */
int certs_cell_cert_add_body(certs_cell_cert_t *inp, uint8_t elt);
/** Return a pointer to the variable-length array field body of 'inp'.
 */
uint8_t * certs_cell_cert_getarray_body(certs_cell_cert_t *inp);
/** As certs_cell_cert_get_body, but take and return a const pointer
 */
const uint8_t  * certs_cell_cert_getconstarray_body(const certs_cell_cert_t *inp);
/** Change the length of the variable-length array field body of 'inp'
 * to 'newlen'.Fill extra elements with 0. Return 0 on success; return
 * -1 and set the error code on 'inp' on failure.
 */
int certs_cell_cert_setlen_body(certs_cell_cert_t *inp, size_t newlen);
/** Return a newly allocated rsa_ed_crosscert with all elements set to
 * zero.
 */
rsa_ed_crosscert_t *rsa_ed_crosscert_new(void);
/** Release all storage held by the rsa_ed_crosscert in 'victim'. (Do
 * nothing if 'victim' is NULL.)
 */
void rsa_ed_crosscert_free(rsa_ed_crosscert_t *victim);
/** Try to parse a rsa_ed_crosscert from the buffer in 'input', using
 * up to 'len_in' bytes from the input buffer. On success, return the
 * number of bytes consumed and set *output to the newly allocated
 * rsa_ed_crosscert_t. On failure, return -2 if the input appears
 * truncated, and -1 if the input is otherwise invalid.
 */
ssize_t rsa_ed_crosscert_parse(rsa_ed_crosscert_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * rsa_ed_crosscert in 'obj'. On failure, return a negative value.
 * Note that this value may be an overestimate, and can even be an
 * underestimate for certain unencodeable objects.
 */
ssize_t rsa_ed_crosscert_encoded_len(const rsa_ed_crosscert_t *obj);
/** Try to encode the rsa_ed_crosscert from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t rsa_ed_crosscert_encode(uint8_t *output, size_t avail, const rsa_ed_crosscert_t *input);
/** Check whether the internal state of the rsa_ed_crosscert in 'obj'
 * is consistent. Return NULL if it is, and a short message if it is
 * not.
 */
const char *rsa_ed_crosscert_check(const rsa_ed_crosscert_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int rsa_ed_crosscert_clear_errors(rsa_ed_crosscert_t *obj);
/** Return the (constant) length of the array holding the ed_key field
 * of the rsa_ed_crosscert_t in 'inp'.
 */
size_t rsa_ed_crosscert_getlen_ed_key(const rsa_ed_crosscert_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * ed_key of the rsa_ed_crosscert_t in 'inp'.
 */
uint8_t rsa_ed_crosscert_get_ed_key(rsa_ed_crosscert_t *inp, size_t idx);
/** As rsa_ed_crosscert_get_ed_key, but take and return a const
 * pointer
 */
uint8_t rsa_ed_crosscert_getconst_ed_key(const rsa_ed_crosscert_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * ed_key of the rsa_ed_crosscert_t in 'inp', so that it will hold the
 * value 'elt'.
 */
int rsa_ed_crosscert_set_ed_key(rsa_ed_crosscert_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field ed_key of 'inp'.
 */
uint8_t * rsa_ed_crosscert_getarray_ed_key(rsa_ed_crosscert_t *inp);
/** As rsa_ed_crosscert_get_ed_key, but take and return a const
 * pointer
 */
const uint8_t  * rsa_ed_crosscert_getconstarray_ed_key(const rsa_ed_crosscert_t *inp);
/** Return the value of the expiration field of the rsa_ed_crosscert_t
 * in 'inp'
 */
uint32_t rsa_ed_crosscert_get_expiration(const rsa_ed_crosscert_t *inp);
/** Set the value of the expiration field of the rsa_ed_crosscert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int rsa_ed_crosscert_set_expiration(rsa_ed_crosscert_t *inp, uint32_t val);
/** Return the position for end_of_signed when we parsed this object
 */
const uint8_t * rsa_ed_crosscert_get_end_of_signed(const rsa_ed_crosscert_t *inp);
/** Return the value of the sig_len field of the rsa_ed_crosscert_t in
 * 'inp'
 */
uint8_t rsa_ed_crosscert_get_sig_len(const rsa_ed_crosscert_t *inp);
/** Set the value of the sig_len field of the rsa_ed_crosscert_t in
 * 'inp' to 'val'. Return 0 on success; return -1 and set the error
 * code on 'inp' on failure.
 */
int rsa_ed_crosscert_set_sig_len(rsa_ed_crosscert_t *inp, uint8_t val);
/** Return the length of the dynamic array holding the sig field of
 * the rsa_ed_crosscert_t in 'inp'.
 */
size_t rsa_ed_crosscert_getlen_sig(const rsa_ed_crosscert_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * sig of the rsa_ed_crosscert_t in 'inp'.
 */
uint8_t rsa_ed_crosscert_get_sig(rsa_ed_crosscert_t *inp, size_t idx);
/** As rsa_ed_crosscert_get_sig, but take and return a const pointer
 */
uint8_t rsa_ed_crosscert_getconst_sig(const rsa_ed_crosscert_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * sig of the rsa_ed_crosscert_t in 'inp', so that it will hold the
 * value 'elt'.
 */
int rsa_ed_crosscert_set_sig(rsa_ed_crosscert_t *inp, size_t idx, uint8_t elt);
/** Append a new element 'elt' to the dynamic array field sig of the
 * rsa_ed_crosscert_t in 'inp'.
 */
int rsa_ed_crosscert_add_sig(rsa_ed_crosscert_t *inp, uint8_t elt);
/** Return a pointer to the variable-length array field sig of 'inp'.
 */
uint8_t * rsa_ed_crosscert_getarray_sig(rsa_ed_crosscert_t *inp);
/** As rsa_ed_crosscert_get_sig, but take and return a const pointer
 */
const uint8_t  * rsa_ed_crosscert_getconstarray_sig(const rsa_ed_crosscert_t *inp);
/** Change the length of the variable-length array field sig of 'inp'
 * to 'newlen'.Fill extra elements with 0. Return 0 on success; return
 * -1 and set the error code on 'inp' on failure.
 */
int rsa_ed_crosscert_setlen_sig(rsa_ed_crosscert_t *inp, size_t newlen);
/** Return a newly allocated auth1 with all elements set to zero.
 */
auth1_t *auth1_new(void);
/** Release all storage held by the auth1 in 'victim'. (Do nothing if
 * 'victim' is NULL.)
 */
void auth1_free(auth1_t *victim);
/** Try to parse a auth1 from the buffer in 'input', using up to
 * 'len_in' bytes from the input buffer. On success, return the number
 * of bytes consumed and set *output to the newly allocated auth1_t.
 * On failure, return -2 if the input appears truncated, and -1 if the
 * input is otherwise invalid.
 */
ssize_t auth1_parse(auth1_t **output, const uint8_t *input, const size_t len_in, const auth_ctx_t *auth_ctx_ctx);
/** Return the number of bytes we expect to need to encode the auth1
 * in 'obj'. On failure, return a negative value. Note that this value
 * may be an overestimate, and can even be an underestimate for
 * certain unencodeable objects.
 */
ssize_t auth1_encoded_len(const auth1_t *obj, const auth_ctx_t *auth_ctx_ctx);
/** Try to encode the auth1 from 'input' into the buffer at 'output',
 * using up to 'avail' bytes of the output buffer. On success, return
 * the number of bytes used. On failure, return -2 if the buffer was
 * not long enough, and -1 if the input was invalid.
 */
ssize_t auth1_encode(uint8_t *output, size_t avail, const auth1_t *input, const auth_ctx_t *auth_ctx_ctx);
/** Check whether the internal state of the auth1 in 'obj' is
 * consistent. Return NULL if it is, and a short message if it is not.
 */
const char *auth1_check(const auth1_t *obj, const auth_ctx_t *auth_ctx_ctx);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int auth1_clear_errors(auth1_t *obj);
/** Return the (constant) length of the array holding the type field
 * of the auth1_t in 'inp'.
 */
size_t auth1_getlen_type(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field type
 * of the auth1_t in 'inp'.
 */
uint8_t auth1_get_type(auth1_t *inp, size_t idx);
/** As auth1_get_type, but take and return a const pointer
 */
uint8_t auth1_getconst_type(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field type
 * of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_type(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 8-element array field type of 'inp'.
 */
uint8_t * auth1_getarray_type(auth1_t *inp);
/** As auth1_get_type, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_type(const auth1_t *inp);
/** Return the (constant) length of the array holding the cid field of
 * the auth1_t in 'inp'.
 */
size_t auth1_getlen_cid(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field cid
 * of the auth1_t in 'inp'.
 */
uint8_t auth1_get_cid(auth1_t *inp, size_t idx);
/** As auth1_get_cid, but take and return a const pointer
 */
uint8_t auth1_getconst_cid(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field cid
 * of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_cid(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field cid of 'inp'.
 */
uint8_t * auth1_getarray_cid(auth1_t *inp);
/** As auth1_get_cid, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_cid(const auth1_t *inp);
/** Return the (constant) length of the array holding the sid field of
 * the auth1_t in 'inp'.
 */
size_t auth1_getlen_sid(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field sid
 * of the auth1_t in 'inp'.
 */
uint8_t auth1_get_sid(auth1_t *inp, size_t idx);
/** As auth1_get_sid, but take and return a const pointer
 */
uint8_t auth1_getconst_sid(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field sid
 * of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_sid(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field sid of 'inp'.
 */
uint8_t * auth1_getarray_sid(auth1_t *inp);
/** As auth1_get_sid, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_sid(const auth1_t *inp);
/** Return the (constant) length of the array holding the u1_cid_ed
 * field of the auth1_t in 'inp'.
 */
size_t auth1_getlen_u1_cid_ed(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * u1_cid_ed of the auth1_t in 'inp'.
 */
uint8_t auth1_get_u1_cid_ed(auth1_t *inp, size_t idx);
/** As auth1_get_u1_cid_ed, but take and return a const pointer
 */
uint8_t auth1_getconst_u1_cid_ed(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * u1_cid_ed of the auth1_t in 'inp', so that it will hold the value
 * 'elt'.
 */
int auth1_set_u1_cid_ed(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field u1_cid_ed of 'inp'.
 */
uint8_t * auth1_getarray_u1_cid_ed(auth1_t *inp);
/** As auth1_get_u1_cid_ed, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_u1_cid_ed(const auth1_t *inp);
/** Return the (constant) length of the array holding the u1_sid_ed
 * field of the auth1_t in 'inp'.
 */
size_t auth1_getlen_u1_sid_ed(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * u1_sid_ed of the auth1_t in 'inp'.
 */
uint8_t auth1_get_u1_sid_ed(auth1_t *inp, size_t idx);
/** As auth1_get_u1_sid_ed, but take and return a const pointer
 */
uint8_t auth1_getconst_u1_sid_ed(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * u1_sid_ed of the auth1_t in 'inp', so that it will hold the value
 * 'elt'.
 */
int auth1_set_u1_sid_ed(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field u1_sid_ed of 'inp'.
 */
uint8_t * auth1_getarray_u1_sid_ed(auth1_t *inp);
/** As auth1_get_u1_sid_ed, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_u1_sid_ed(const auth1_t *inp);
/** Return the (constant) length of the array holding the slog field
 * of the auth1_t in 'inp'.
 */
size_t auth1_getlen_slog(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field slog
 * of the auth1_t in 'inp'.
 */
uint8_t auth1_get_slog(auth1_t *inp, size_t idx);
/** As auth1_get_slog, but take and return a const pointer
 */
uint8_t auth1_getconst_slog(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field slog
 * of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_slog(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field slog of 'inp'.
 */
uint8_t * auth1_getarray_slog(auth1_t *inp);
/** As auth1_get_slog, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_slog(const auth1_t *inp);
/** Return the (constant) length of the array holding the clog field
 * of the auth1_t in 'inp'.
 */
size_t auth1_getlen_clog(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field clog
 * of the auth1_t in 'inp'.
 */
uint8_t auth1_get_clog(auth1_t *inp, size_t idx);
/** As auth1_get_clog, but take and return a const pointer
 */
uint8_t auth1_getconst_clog(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field clog
 * of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_clog(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field clog of 'inp'.
 */
uint8_t * auth1_getarray_clog(auth1_t *inp);
/** As auth1_get_clog, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_clog(const auth1_t *inp);
/** Return the (constant) length of the array holding the scert field
 * of the auth1_t in 'inp'.
 */
size_t auth1_getlen_scert(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * scert of the auth1_t in 'inp'.
 */
uint8_t auth1_get_scert(auth1_t *inp, size_t idx);
/** As auth1_get_scert, but take and return a const pointer
 */
uint8_t auth1_getconst_scert(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * scert of the auth1_t in 'inp', so that it will hold the value
 * 'elt'.
 */
int auth1_set_scert(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field scert of 'inp'.
 */
uint8_t * auth1_getarray_scert(auth1_t *inp);
/** As auth1_get_scert, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_scert(const auth1_t *inp);
/** Return the (constant) length of the array holding the tlssecrets
 * field of the auth1_t in 'inp'.
 */
size_t auth1_getlen_tlssecrets(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field
 * tlssecrets of the auth1_t in 'inp'.
 */
uint8_t auth1_get_tlssecrets(auth1_t *inp, size_t idx);
/** As auth1_get_tlssecrets, but take and return a const pointer
 */
uint8_t auth1_getconst_tlssecrets(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field
 * tlssecrets of the auth1_t in 'inp', so that it will hold the value
 * 'elt'.
 */
int auth1_set_tlssecrets(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 32-element array field tlssecrets of
 * 'inp'.
 */
uint8_t * auth1_getarray_tlssecrets(auth1_t *inp);
/** As auth1_get_tlssecrets, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_tlssecrets(const auth1_t *inp);
/** Return the position for end_of_fixed_part when we parsed this
 * object
 */
const uint8_t * auth1_get_end_of_fixed_part(const auth1_t *inp);
/** Return the (constant) length of the array holding the rand field
 * of the auth1_t in 'inp'.
 */
size_t auth1_getlen_rand(const auth1_t *inp);
/** Return the element at position 'idx' of the fixed array field rand
 * of the auth1_t in 'inp'.
 */
uint8_t auth1_get_rand(auth1_t *inp, size_t idx);
/** As auth1_get_rand, but take and return a const pointer
 */
uint8_t auth1_getconst_rand(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the fixed array field rand
 * of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_rand(auth1_t *inp, size_t idx, uint8_t elt);
/** Return a pointer to the 24-element array field rand of 'inp'.
 */
uint8_t * auth1_getarray_rand(auth1_t *inp);
/** As auth1_get_rand, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_rand(const auth1_t *inp);
/** Return the position for end_of_signed when we parsed this object
 */
const uint8_t * auth1_get_end_of_signed(const auth1_t *inp);
/** Return the length of the dynamic array holding the sig field of
 * the auth1_t in 'inp'.
 */
size_t auth1_getlen_sig(const auth1_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * sig of the auth1_t in 'inp'.
 */
uint8_t auth1_get_sig(auth1_t *inp, size_t idx);
/** As auth1_get_sig, but take and return a const pointer
 */
uint8_t auth1_getconst_sig(const auth1_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * sig of the auth1_t in 'inp', so that it will hold the value 'elt'.
 */
int auth1_set_sig(auth1_t *inp, size_t idx, uint8_t elt);
/** Append a new element 'elt' to the dynamic array field sig of the
 * auth1_t in 'inp'.
 */
int auth1_add_sig(auth1_t *inp, uint8_t elt);
/** Return a pointer to the variable-length array field sig of 'inp'.
 */
uint8_t * auth1_getarray_sig(auth1_t *inp);
/** As auth1_get_sig, but take and return a const pointer
 */
const uint8_t  * auth1_getconstarray_sig(const auth1_t *inp);
/** Change the length of the variable-length array field sig of 'inp'
 * to 'newlen'.Fill extra elements with 0. Return 0 on success; return
 * -1 and set the error code on 'inp' on failure.
 */
int auth1_setlen_sig(auth1_t *inp, size_t newlen);
/** Return a newly allocated certs_cell with all elements set to zero.
 */
certs_cell_t *certs_cell_new(void);
/** Release all storage held by the certs_cell in 'victim'. (Do
 * nothing if 'victim' is NULL.)
 */
void certs_cell_free(certs_cell_t *victim);
/** Try to parse a certs_cell from the buffer in 'input', using up to
 * 'len_in' bytes from the input buffer. On success, return the number
 * of bytes consumed and set *output to the newly allocated
 * certs_cell_t. On failure, return -2 if the input appears truncated,
 * and -1 if the input is otherwise invalid.
 */
ssize_t certs_cell_parse(certs_cell_t **output, const uint8_t *input, const size_t len_in);
/** Return the number of bytes we expect to need to encode the
 * certs_cell in 'obj'. On failure, return a negative value. Note that
 * this value may be an overestimate, and can even be an underestimate
 * for certain unencodeable objects.
 */
ssize_t certs_cell_encoded_len(const certs_cell_t *obj);
/** Try to encode the certs_cell from 'input' into the buffer at
 * 'output', using up to 'avail' bytes of the output buffer. On
 * success, return the number of bytes used. On failure, return -2 if
 * the buffer was not long enough, and -1 if the input was invalid.
 */
ssize_t certs_cell_encode(uint8_t *output, size_t avail, const certs_cell_t *input);
/** Check whether the internal state of the certs_cell in 'obj' is
 * consistent. Return NULL if it is, and a short message if it is not.
 */
const char *certs_cell_check(const certs_cell_t *obj);
/** Clear any errors that were set on the object 'obj' by its setter
 * functions. Return true iff errors were cleared.
 */
int certs_cell_clear_errors(certs_cell_t *obj);
/** Return the value of the n_certs field of the certs_cell_t in 'inp'
 */
uint8_t certs_cell_get_n_certs(const certs_cell_t *inp);
/** Set the value of the n_certs field of the certs_cell_t in 'inp' to
 * 'val'. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int certs_cell_set_n_certs(certs_cell_t *inp, uint8_t val);
/** Return the length of the dynamic array holding the certs field of
 * the certs_cell_t in 'inp'.
 */
size_t certs_cell_getlen_certs(const certs_cell_t *inp);
/** Return the element at position 'idx' of the dynamic array field
 * certs of the certs_cell_t in 'inp'.
 */
struct certs_cell_cert_st * certs_cell_get_certs(certs_cell_t *inp, size_t idx);
/** As certs_cell_get_certs, but take and return a const pointer
 */
 const struct certs_cell_cert_st * certs_cell_getconst_certs(const certs_cell_t *inp, size_t idx);
/** Change the element at position 'idx' of the dynamic array field
 * certs of the certs_cell_t in 'inp', so that it will hold the value
 * 'elt'. Free the previous value, if any.
 */
int certs_cell_set_certs(certs_cell_t *inp, size_t idx, struct certs_cell_cert_st * elt);
/** As certs_cell_set_certs, but does not free the previous value.
 */
int certs_cell_set0_certs(certs_cell_t *inp, size_t idx, struct certs_cell_cert_st * elt);
/** Append a new element 'elt' to the dynamic array field certs of the
 * certs_cell_t in 'inp'.
 */
int certs_cell_add_certs(certs_cell_t *inp, struct certs_cell_cert_st * elt);
/** Return a pointer to the variable-length array field certs of
 * 'inp'.
 */
struct certs_cell_cert_st * * certs_cell_getarray_certs(certs_cell_t *inp);
/** As certs_cell_get_certs, but take and return a const pointer
 */
const struct certs_cell_cert_st *  const  * certs_cell_getconstarray_certs(const certs_cell_t *inp);
/** Change the length of the variable-length array field certs of
 * 'inp' to 'newlen'.Fill extra elements with NULL; free removed
 * elements. Return 0 on success; return -1 and set the error code on
 * 'inp' on failure.
 */
int certs_cell_setlen_certs(certs_cell_t *inp, size_t newlen);


#endif