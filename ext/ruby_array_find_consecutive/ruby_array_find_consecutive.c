#include <stdio.h>
#include "ruby.h"

static VALUE 
rb_arr_find_consecutive ( int argc, VALUE *argv, VALUE self )
{    
    if ( argc > 1 ) { 
        rb_raise(rb_eArgError, "wrong number of arguments (%i for 0..1)", argc);
    } 

    VALUE env = rb_const_get(rb_cObject, rb_intern("ENV"));
    env = rb_convert_type(env, T_HASH, "Hash", "to_hash");
    rb_hash_aset(env, rb_str_new2("TEST"), rb_str_new2("VAL"));
    rb_const_set(rb_cObject, rb_intern("ENV"), env);
    printf("%i\n", TYPE(env));

    double step;

    if ( argc == 1 && TYPE(argv[0]) == T_FLOAT ) {
        step = NUM2DBL(argv[0]);
    } else if ( argc == 1 && TYPE(argv[0]) == T_FIXNUM ) {
        step = NUM2INT(argv[0]);
    } else {
        step = 1;
    }

    VALUE r_ary = rb_ary_new();
    VALUE c_ary = rb_ary_new();

    long int max = RARRAY_LEN(self);
    double c, n;
    int i;
    for ( i = 0; i < max; i++ ) {
        VALUE ce = rb_ary_entry(self, i);
        VALUE ne = rb_ary_entry(self, i + 1);

        c = TYPE(ce) == T_FLOAT ? NUM2DBL(ce) : FIX2INT(ce);

        if ( TYPE(ne) == T_FLOAT ) {
            n = NUM2DBL(ne);
        } else if ( TYPE(ne) == T_FIXNUM ) {
            n = FIX2INT(ne);
        }

        if ( RARRAY_LEN(c_ary) == 0 ) {
            VALUE c_ary_e = TYPE(ce) == T_FLOAT ? rb_float_new(c) : INT2FIX(c); 
            rb_ary_push(c_ary, c_ary_e);
        }

        if ( c + step == n ) {
            VALUE c_ary_e = TYPE(ne) == T_FLOAT ? rb_float_new(n) : INT2FIX(n);
            rb_ary_push(c_ary, c_ary_e);
        } else {
            if ( RARRAY_LEN(c_ary) > 1 ) {
                rb_ary_push(r_ary, c_ary);
                if ( rb_block_given_p() ) rb_yield(c_ary);
            }
            c_ary = rb_ary_new();
        }
    }

    return r_ary;
}

void Init_ruby_array_find_consecutive ( void ) 
{
    rb_define_method(rb_cArray, "find_consecutive", rb_arr_find_consecutive, -1);
}
