
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Fastorm_Db_Query) {

	ZEPHIR_REGISTER_CLASS(Fastorm\\Db, Query, fastorm, db_query, fastorm_db_query_method_entry, 0);

	zend_declare_property_null(fastorm_db_query_ce, SL("masks"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("modifiers"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("separators"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("swithes"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("_command"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("setups"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("_cursor"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(fastorm_db_query_ce, SL("_clauses"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_bool(fastorm_db_query_ce, SL("REMOVE"), 0 TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_TEXT"), "s" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_BINARY"), "bin" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_BOOL"), "b" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_INTEGER"), "i" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_FLOAT"), "f" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_DATE"), "d" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_DATETIME"), "t" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("TYPE_TIME"), "t" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("IDENTIFIER"), "n" TSRMLS_CC);

	/** sorting order */
	zend_declare_class_constant_string(fastorm_db_query_ce, SL("ASC"), "ASC" TSRMLS_CC);

	zend_declare_class_constant_string(fastorm_db_query_ce, SL("DESC"), "DESC" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Fastorm_Db_Query, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	if (!(zephir_instance_of_ev(connection, fastorm_db_connection_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'connection' must be an instance of 'Fastorm\\Db\\Connection'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("connection"), connection TSRMLS_CC);
	_0 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("masks") TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "staticinitialize", &_1);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("setups"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Fastorm_Db_Query, staticInitialize) {

	zval *_2;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 6);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 12);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "SELECT", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "DISTINCT", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "FROM", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "WHERE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "GROUP BY", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "HAVING", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "ORDER BY", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "LIMIT", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "OFFSET", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("SELECT"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	array_init_size(_1, 7);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "UPDATE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "SET", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "WHERE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "ORDER BY", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "LIMIT", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("UPDATE"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	array_init_size(_1, 6);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "INSERT", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "INTO", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "VALUES", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "SELECT", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("INSERT"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	array_init_size(_1, 8);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "DELETE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "FROM", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "USING", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "WHERE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "ORDER BY", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "LIMIT", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("DELETE"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(fastorm_db_query_ce, SL("masks"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	array_init_size(_0, 12);
	add_assoc_stringl_ex(_0, SS("SELECT"), SL("%n"), 1);
	add_assoc_stringl_ex(_0, SS("FROM"), SL("%n"), 1);
	add_assoc_stringl_ex(_0, SS("IN"), SL("%in"), 1);
	add_assoc_stringl_ex(_0, SS("VALUES"), SL("%l"), 1);
	add_assoc_stringl_ex(_0, SS("SET"), SL("%a"), 1);
	add_assoc_stringl_ex(_0, SS("WHERE"), SL("%and"), 1);
	add_assoc_stringl_ex(_0, SS("HAVING"), SL("%and"), 1);
	add_assoc_stringl_ex(_0, SS("ORDER BY"), SL("%by"), 1);
	add_assoc_stringl_ex(_0, SS("GROUP BY"), SL("%by"), 1);
	zephir_update_static_property_ce(fastorm_db_query_ce, SL("modifiers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	array_init_size(_0, 14);
	add_assoc_stringl_ex(_0, SS("SELECT"), SL(","), 1);
	add_assoc_stringl_ex(_0, SS("FROM"), SL(","), 1);
	add_assoc_stringl_ex(_0, SS("WHERE"), SL("AND"), 1);
	add_assoc_stringl_ex(_0, SS("GROUP BY"), SL(","), 1);
	add_assoc_stringl_ex(_0, SS("HAVING"), SL("AND"), 1);
	add_assoc_stringl_ex(_0, SS("ORDER BY"), SL(","), 1);
	zephir_array_update_string(&_0, SL("LIMIT"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("OFFSET"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("SET"), SL(","), 1);
	add_assoc_stringl_ex(_0, SS("VALUES"), SL(","), 1);
	zephir_array_update_string(&_0, SL("INTO"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(fastorm_db_query_ce, SL("separators"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_0);
	array_init_size(_0, 6);
	add_assoc_stringl_ex(_0, SS("JOIN"), SL("FROM"), 1);
	add_assoc_stringl_ex(_0, SS("INNER JOIN"), SL("FROM"), 1);
	add_assoc_stringl_ex(_0, SS("LEFT JOIN"), SL("FROM"), 1);
	add_assoc_stringl_ex(_0, SS("RIGHT JOIN"), SL("FROM"), 1);
	zephir_update_static_property_ce(fastorm_db_query_ce, SL("swithes"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Fastorm_Db_Query, __call) {

	HashTable *_23;
	HashPosition _22;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_17 = NULL, *_21 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool removeArray, _0, _14, _18, _19;
	zval *clause_param = NULL, *args = NULL, *sep, *arg = NULL, *_1, *_2 = NULL, *_3, *_5, *_6, *_7, *_8 = NULL, *_9, *_10, *_11 = NULL, *_12, *_13, _15, *_16 = NULL, *_20 = NULL, **_24;
	zval *clause = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &clause_param, &args);

	zephir_get_strval(clause, clause_param);
	ZEPHIR_SEPARATE_PARAM(clause);
	ZEPHIR_SEPARATE_PARAM(args);


	_0 = zephir_fast_count_int(args TSRMLS_CC) == 1;
	if (_0) {
		zephir_array_fetch_long(&_1, args, 0, PH_NOISY | PH_READONLY, "fastorm/db/Query.zep", 100 TSRMLS_CC);
		_0 = ZEPHIR_IS_FALSE_IDENTICAL(_1);
	}
	removeArray = _0;
	ZEPHIR_CALL_SELF(&_2, "_formatclause", NULL, clause);
	zephir_check_call_status();
	zephir_get_strval(clause, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_command"), PH_NOISY_CC);
	if (Z_TYPE_P(_3) == IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", &_4, clause);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("swithes") TSRMLS_CC);
	if (zephir_array_isset(_5, clause)) {
		_6 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("swithes") TSRMLS_CC);
		zephir_array_fetch(&_7, _6, clause, PH_NOISY | PH_READONLY, "fastorm/db/Query.zep", 110 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_cursor"), _7 TSRMLS_CC);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_clauses"), PH_NOISY_CC);
	if (zephir_array_key_exists(_6, clause TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_cursor"), clause TSRMLS_CC);
		if (removeArray) {
			ZEPHIR_OBS_VAR(_8);
			zephir_read_property_this(&_8, this_ptr, SL("_cursor"), PH_NOISY_CC);
			zephir_update_property_array(this_ptr, SL("clauses"), _8, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
			RETURN_THIS();
		}
		_9 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("separators") TSRMLS_CC);
		if (zephir_array_isset(_9, clause)) {
			_10 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("separators") TSRMLS_CC);
			ZEPHIR_OBS_VAR(sep);
			zephir_array_fetch(&sep, _10, clause, PH_NOISY, "fastorm/db/Query.zep", 123 TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(sep)) {
				ZEPHIR_INIT_VAR(_11);
				array_init(_11);
				zephir_update_property_array(this_ptr, SL("_clauses"), clause, _11 TSRMLS_CC);
			} else {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_clauses"), PH_NOISY_CC);
				zephir_array_fetch(&_7, _12, clause, PH_NOISY | PH_READONLY, "fastorm/db/Query.zep", 127 TSRMLS_CC);
				if (!(ZEPHIR_IS_EMPTY(_7))) {
					zephir_update_property_array_multi(this_ptr, SL("_clauses"), &sep TSRMLS_CC, SL("za"), 1, clause);
				}
			}
		}
	} else {
		if (removeArray) {
			RETURN_THIS();
		}
		ZEPHIR_OBS_NVAR(_8);
		zephir_read_property_this(&_8, this_ptr, SL("_cursor"), PH_NOISY_CC);
		zephir_update_property_array_multi(this_ptr, SL("_clauses"), &clause TSRMLS_CC, SL("za"), 1, _8);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_cursor"), PH_NOISY_CC);
	if (Z_TYPE_P(_6) == IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_cursor"), clause TSRMLS_CC);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_clauses"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_cursor"), PH_NOISY_CC);
	if (!(zephir_array_isset(_6, _9))) {
		ZEPHIR_INIT_NVAR(_11);
		array_init(_11);
		ZEPHIR_OBS_VAR(_13);
		zephir_read_property_this(&_13, this_ptr, SL("_cursor"), PH_NOISY_CC);
		zephir_update_property_array(this_ptr, SL("_clauses"), _13, _11 TSRMLS_CC);
	}
	if (zephir_fast_count_int(args TSRMLS_CC) == 1) {
		ZEPHIR_OBS_VAR(arg);
		zephir_array_fetch_long(&arg, args, 0, PH_NOISY, "fastorm/db/Query.zep", 153 TSRMLS_CC);
		if (ZEPHIR_IS_TRUE_IDENTICAL(arg)) {
			RETURN_THIS();
		}
		_14 = Z_TYPE_P(arg) == IS_STRING;
		if (_14) {
			ZEPHIR_SINIT_VAR(_15);
			ZVAL_STRING(&_15, "#^[a-z:_][a-z0-9_.:]*$#i", 0);
			ZEPHIR_CALL_FUNCTION(&_16, "preg_match", &_17, &_15, arg);
			zephir_check_call_status();
			_14 = zephir_is_true(_16);
		}
		if (_14) {
			ZEPHIR_INIT_NVAR(args);
			array_init_size(args, 3);
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "%n", 1);
			zephir_array_fast_append(args, _11);
			zephir_array_fast_append(args, arg);
		} else {
			_18 = Z_TYPE_P(arg) == IS_ARRAY;
			if (!(_18)) {
				_19 = (zephir_is_instance_of(arg, SL("Traversable") TSRMLS_CC));
				if (_19) {
					_19 = !(zephir_is_instance_of(arg, SL("Fastorm\\Db\\self") TSRMLS_CC));
				}
				_18 = _19;
			}
			if (_18) {
				_6 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("modifiers") TSRMLS_CC);
				if (zephir_array_isset(_6, clause)) {
					ZEPHIR_INIT_NVAR(args);
					array_init_size(args, 3);
					_9 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("modifiers") TSRMLS_CC);
					ZEPHIR_OBS_NVAR(_8);
					zephir_array_fetch(&_8, _9, clause, PH_NOISY, "fastorm/db/Query.zep", 166 TSRMLS_CC);
					zephir_array_fast_append(args, _8);
					zephir_array_fast_append(args, arg);
				} else {
					Z_SET_ISREF_P(arg);
					ZEPHIR_CALL_FUNCTION(&_20, "key", &_21, arg);
					Z_UNSET_ISREF_P(arg);
					zephir_check_call_status();
					if (Z_TYPE_P(_20) == IS_STRING) {
						ZEPHIR_INIT_NVAR(args);
						array_init_size(args, 3);
						ZEPHIR_INIT_NVAR(_11);
						ZVAL_STRING(_11, "%a", 1);
						zephir_array_fast_append(args, _11);
						zephir_array_fast_append(args, arg);
					}
				}
			}
		}
	}
	zephir_is_iterable(args, &_23, &_22, 0, 0, "fastorm/db/Query.zep", 183);
	for (
	  ; zephir_hash_get_current_data_ex(_23, (void**) &_24, &_22) == SUCCESS
	  ; zephir_hash_move_forward_ex(_23, &_22)
	) {
		ZEPHIR_GET_HVALUE(arg, _24);
		if (zephir_is_instance_of(arg, SL("Fastorm\\Db\\self") TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_16, arg, "__tostring",  NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(arg);
			ZEPHIR_CONCAT_SVS(arg, "(", _16, ")");
		}
		ZEPHIR_OBS_NVAR(_8);
		zephir_read_property_this(&_8, this_ptr, SL("_cursor"), PH_NOISY_CC);
		zephir_update_property_array_multi(this_ptr, SL("_clauses"), &arg TSRMLS_CC, SL("za"), 1, _8);
	}
	RETURN_THIS();

}

PHP_METHOD(Fastorm_Db_Query, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *clause_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_5;
	zval *clause = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &clause_param);

	zephir_get_strval(clause, clause_param);


	_0 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("masks") TSRMLS_CC);
	if (zephir_array_isset(_0, clause)) {
		_1 = zephir_fetch_static_property_ce(fastorm_db_query_ce, SL("masks") TSRMLS_CC);
		zephir_array_fetch(&_2, _1, clause, PH_NOISY | PH_READONLY, "fastorm/db/Query.zep", 188 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "array_fill_keys", &_4, _2, ZEPHIR_GLOBAL(global_null));
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_clauses"), _3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_5);
		array_init(_5);
		zephir_update_property_this(this_ptr, SL("_clauses"), _5 TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_cursor"), clause TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_command"), clause TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Fastorm_Db_Query, _formatClause) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zend_bool _0;
	zval *s_param = NULL, _1, _2, *_3 = NULL;
	zval *s = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);

	zephir_get_strval(s, s_param);
	ZEPHIR_SEPARATE_PARAM(s);


	_0 = ZEPHIR_IS_STRING_IDENTICAL(s, "order");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(s, "group");
	}
	if (_0) {
		zephir_concat_self_str(&s, "By", sizeof("By")-1 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "#[a-z](?=[A-Z])#", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "$0 ", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", &_4, &_1, &_2, s);
	zephir_check_call_status();
	zephir_fast_strtoupper(return_value, _3);
	RETURN_MM();

}

/**
 * Returns SQL command.
 * @return string
 */
PHP_METHOD(Fastorm_Db_Query, getCommand) {


	RETURN_MEMBER(this_ptr, "_command");

}

PHP_METHOD(Fastorm_Db_Query, getConnection) {


	RETURN_MEMBER(this_ptr, "connection");

}

PHP_METHOD(Fastorm_Db_Query, setupResult) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *method, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", &_1);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("setups"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Fastorm_Db_Query, execute) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ret = NULL, *res = NULL, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &ret);

	if (!ret) {
		ret = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_export",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&res, this_ptr, "query", &_1, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(ret, "n")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_2, "getinsertid", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_CCTOR(res);
	}

}

PHP_METHOD(Fastorm_Db_Query, fetchRow) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_3;
	zval *_0, *_1 = NULL, *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_command"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING_IDENTICAL(_0, "SELECT")) {
		ZEPHIR_INIT_VAR(_3);
		array_init_size(_3, 3);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "%lmt", 1);
		zephir_array_fast_append(_3, _4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 1);
		zephir_array_fast_append(_3, _4);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_export", NULL, ZEPHIR_GLOBAL(global_null), _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "query", &_5, _2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_1, "fetchrow", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_export",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "query", &_5, _2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_1, "fetchrow", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Fastorm_Db_Query, fetchSingle) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_3;
	zval *_0, *_1 = NULL, *_2 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_command"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING_IDENTICAL(_0, "SELECT")) {
		ZEPHIR_INIT_VAR(_3);
		array_init_size(_3, 3);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "%lmt", 1);
		zephir_array_fast_append(_3, _4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 1);
		zephir_array_fast_append(_3, _4);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_export", NULL, ZEPHIR_GLOBAL(global_null), _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "query", &_5, _2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_1, "fetchsingle", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_export",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "query", &_5, _2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_1, "fetchsingle", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Fastorm_Db_Query, fetchAssoc) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *assoc, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &assoc);



	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_export",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "query", &_2, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetchassoc", NULL, assoc);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fastorm_Db_Query, fetchPairs) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, *_0 = NULL, *_1 = NULL;
	zval *key = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &value_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}
	if (!value_param) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	} else {
		zephir_get_strval(value, value_param);
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_export",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "query", &_2, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetchpairs", NULL, key, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fastorm_Db_Query, getIterator) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2;
	zval *offset = NULL, *limit = NULL, *_0 = NULL, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &offset, &limit);

	if (!offset) {
		offset = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit) {
		limit = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 4);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "%ofs %lmt", 1);
	zephir_array_fast_append(_2, _3);
	zephir_array_fast_append(_2, offset);
	zephir_array_fast_append(_2, limit);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_export", NULL, ZEPHIR_GLOBAL(global_null), _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "query", &_4, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "getiterator", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fastorm_Db_Query, count) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 4);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "SELECT COUNT(*) FROM (%ex", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_export",  NULL);
	zephir_check_call_status();
	zephir_array_fast_append(_1, _3);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, ") AS [data]", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "query", &_4, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, _0, "fetchsingle",  NULL);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_3));

}

PHP_METHOD(Fastorm_Db_Query, query) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zval *_6 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *args, *res = NULL, *setup = NULL, *_0, *_1, **_4, *_5 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&res, _0, "query", NULL, args);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("setups"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "fastorm/db/Query.zep", 310);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(setup, _4);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_INIT_NVAR(_6);
		array_init_size(_6, 3);
		zephir_array_fast_append(_6, res);
		Z_SET_ISREF_P(setup);
		ZEPHIR_CALL_FUNCTION(&_7, "array_shift", &_8, setup);
		Z_UNSET_ISREF_P(setup);
		zephir_check_call_status();
		zephir_array_fast_append(_6, _7);
		ZEPHIR_CALL_USER_FUNC_ARRAY(_5, _6, setup);
		zephir_check_call_status();
	}
	RETURN_CCTOR(res);

}

PHP_METHOD(Fastorm_Db_Query, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_export",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "translate", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Fastorm_Db_Query, _export) {

	HashTable *_5, *_8;
	HashPosition _4, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *clause = NULL, *args = NULL, *data = NULL, *cls = NULL, *statement = NULL, *arg = NULL, *_0 = NULL, *_1, *_2, *_3, **_6, **_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &clause, &args);

	if (!clause) {
		ZEPHIR_CPY_WRT(clause, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(clause);
	}
	if (!args) {
		ZEPHIR_CPY_WRT(args, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(args);
	}


	if (Z_TYPE_P(args) == IS_NULL) {
		ZEPHIR_INIT_NVAR(args);
		array_init(args);
	}
	if (Z_TYPE_P(clause) == IS_NULL) {
		ZEPHIR_OBS_VAR(data);
		zephir_read_property_this(&data, this_ptr, SL("_clauses"), PH_NOISY_CC);
	} else {
		ZEPHIR_CALL_SELF(&_0, "_formatclause", NULL, clause);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(clause, _0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_clauses"), PH_NOISY_CC);
		if (zephir_array_key_exists(_1, clause TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(data);
			array_init_size(data, 2);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_clauses"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_3);
			zephir_array_fetch(&_3, _2, clause, PH_NOISY, "fastorm/db/Query.zep", 337 TSRMLS_CC);
			zephir_array_update_zval(&data, clause, &_3, PH_COPY);
		} else {
			array_init(return_value);
			RETURN_MM();
		}
	}
	zephir_is_iterable(data, &_5, &_4, 0, 0, "fastorm/db/Query.zep", 355);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(cls, _5, _4);
		ZEPHIR_GET_HVALUE(statement, _6);
		if (Z_TYPE_P(statement) != IS_NULL) {
			zephir_array_append(&args, clause, PH_SEPARATE, "fastorm/db/Query.zep", 345);
			zephir_is_iterable(statement, &_8, &_7, 0, 0, "fastorm/db/Query.zep", 352);
			for (
			  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
			  ; zephir_hash_move_forward_ex(_8, &_7)
			) {
				ZEPHIR_GET_HVALUE(arg, _9);
				zephir_array_append(&args, arg, PH_SEPARATE, "fastorm/db/Query.zep", 350);
			}
		}
	}
	RETURN_CCTOR(args);

}

