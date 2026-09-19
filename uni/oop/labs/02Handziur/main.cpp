// Developed by Handziur Dmytro on 21.02.2026
#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
#include <numbers>
#include <cassert>
#include <type_traits>

using std::cout;

int main()
{
    double pi = std::numbers::pi;
    std::string separator = "\n----------------------------\n";

    AComplex alg1(12, 3);
    AComplex alg2(4, -1);
    TComplex tri1(5, pi / 2);
    TComplex tri2(10, pi / 2 * 3);
    double real = 10;

    cout << "** Given values **\n";
    cout << "AComplex1: " << alg1 << '\n';
    cout << "AComplex2: " << alg2 << '\n';
    cout << "TComplex1: " << tri1 << '\n';
    cout << "TComplex2: " << tri2 << '\n';
    cout << "real: " << real << '\n';

    cout << separator;

    cout << "** Chained test **\n";
    auto chained_res = (alg1 * 3 + 4) / 2 - 1;
    assert((std::is_same_v<decltype(chained_res), AComplex>));
    cout << '(' << alg1 << " * 3 + 4) / 2 - 1 = " << chained_res << " (AC)";

    cout << separator;
    cout << "** Every operation test **\n";
    cout << separator;

    cout << "** '+' & '-' ops => AComplex **\n\n";

    cout << "TEST #1 AC + AC\n";
    auto ac_plus_ac = alg1 + alg2;
    assert((std::is_same_v<decltype(ac_plus_ac), AComplex>));
    cout << alg1 << " (AC)\t+\t" << alg2 << " (AC)\t=\t" << ac_plus_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #2 AC - AC\n";
    auto ac_minus_ac = alg1 - alg2;
    assert((std::is_same_v<decltype(ac_minus_ac), AComplex>));
    cout << alg1 << " (AC)\t-\t" << alg2 << " (AC)\t=\t" << ac_minus_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #3 AC + TC\n";
    auto ac_plus_tc = alg1 + tri2;
    assert((std::is_same_v<decltype(ac_plus_tc), AComplex>));
    cout << alg1 << " (AC)\t+\t" << tri2 << " (TC)\t=\t" << ac_plus_tc << " (AC)\n\n";

    cout << separator;

    cout << "TEST #4 AC - TC\n";
    auto ac_minus_tc = alg1 - tri2;
    assert((std::is_same_v<decltype(ac_minus_tc), AComplex>));
    cout << alg1 << " (AC)\t-\t" << tri2 << " (TC)\t=\t" << ac_minus_tc << " (AC)\n\n";

    cout << separator;

    cout << "TEST #5 TC + AC\n";
    auto tc_plus_ac = tri1 + alg2;
    assert((std::is_same_v<decltype(tc_plus_ac), AComplex>));
    cout << tri1 << " (TC)\t+\t" << alg2 << " (AC)\t=\t" << tc_plus_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #6 TC - AC\n";
    auto tc_minus_ac = tri1 - alg2;
    assert((std::is_same_v<decltype(tc_minus_ac), AComplex>));
    cout << tri1 << " (TC)\t-\t" << alg2 << " (AC)\t=\t" << tc_minus_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #7 TC + TC\n";
    auto tc_plus_tc = tri1 + tri2;
    assert((std::is_same_v<decltype(tc_plus_tc), AComplex>));
    cout << tri1 << " (TC)\t+\t" << tri2 << " (TC)\t=\t" << tc_plus_tc << " (AC)\n\n";

    cout << separator;

    cout << "TEST #8 TC - TC\n";
    auto tc_minus_tc = tri1 - tri2;
    assert((std::is_same_v<decltype(tc_minus_tc), AComplex>));
    cout << tri1 << " (TC)\t-\t" << tri2 << " (TC)\t=\t" << tc_minus_tc << " (AC)\n\n";

    cout << separator;

    /* real numbers */
    cout << "TEST #9 AC + real\n";
    auto ac_plus_re = alg1 + real;
    assert((std::is_same_v<decltype(ac_plus_re), AComplex>));
    cout << alg1 << " (AC)\t+\t" << real << " (real)\t=\t" << ac_plus_re << " (AC)\n\n";

    cout << separator;

    cout << "TEST #10 TC + real\n";
    auto tc_plus_re = tri1 + real;
    assert((std::is_same_v<decltype(tc_plus_re), AComplex>));
    cout << tri1 << " (TC)\t+\t" << real << " (real)\t=\t" << tc_plus_re << " (AC)\n\n";

    cout << separator;

    cout << "TEST #11 AC - real\n";
    auto ac_minus_re = alg1 - real;
    assert((std::is_same_v<decltype(ac_minus_re), AComplex>));
    cout << alg1 << " (AC)\t-\t" << real << " (real)\t=\t" << ac_minus_re << " (AC)\n\n";

    cout << separator;

    cout << "TEST #12 TC - real\n";
    auto tc_minus_re = tri1 - real;
    assert((std::is_same_v<decltype(tc_minus_re), AComplex>));
    cout << tri1 << " (TC)\t-\t" << real << " (real)\t=\t" << tc_minus_re << " (AC)\n\n";

    cout << separator;

    cout << "TEST #13 real + AC\n";
    auto re_plus_ac = real + alg1;
    assert((std::is_same_v<decltype(re_plus_ac), AComplex>));
    cout << real << " (real)\t+\t" << alg1 << " (AC)\t=\t" << re_plus_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #14 real + TC\n";
    auto re_plus_tc = real + tri1;
    assert((std::is_same_v<decltype(re_plus_tc), AComplex>));
    cout << real << " (real)\t+\t" << tri1 << " (TC)\t=\t" << re_plus_tc << " (AC)\n\n";

    cout << separator;

    cout << "TEST #15 real - AC\n";
    auto re_minus_ac = real - alg1;
    assert((std::is_same_v<decltype(re_minus_ac), AComplex>));
    cout << real << " (real)\t-\t" << alg1 << " (AC)\t=\t" << re_minus_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #16 real - TC\n";
    auto re_minus_tc = real - tri1;
    assert((std::is_same_v<decltype(re_minus_tc), AComplex>));
    cout << real << " (real)\t-\t" << tri1 << " (TC)\t=\t" << re_minus_tc << " (AC)\n\n";

    cout << separator;

    cout << "** '*' & '/' ops => TComplex **\n\n";

    cout << "TEST #17 AC * AC\n";
    auto ac_mul_ac = alg1 * alg2;
    assert((std::is_same_v<decltype(ac_mul_ac), TComplex>));
    cout << alg1 << " (AC)\t*\t" << alg2 << " (AC)\t=\t" << ac_mul_ac << " (TC)\n\n";

    cout << separator;

    cout << "TEST #18 AC / AC\n";
    auto ac_div_ac = alg1 / alg2;
    assert((std::is_same_v<decltype(ac_div_ac), TComplex>));
    cout << alg1 << " (AC)\t/\t" << alg2 << " (AC)\t=\t" << ac_div_ac << " (TC)\n\n";

    cout << separator;

    cout << "TEST #19 AC * TC\n";
    auto ac_mul_tc = alg1 * tri2;
    assert((std::is_same_v<decltype(ac_mul_tc), TComplex>));
    cout << alg1 << " (AC)\t*\t" << tri2 << " (TC)\t=\t" << ac_mul_tc << " (TC)\n\n";

    cout << separator;

    cout << "TEST #20 AC / TC\n";
    auto ac_div_tc = alg1 / tri2;
    assert((std::is_same_v<decltype(ac_div_tc), TComplex>));
    cout << alg1 << " (AC)\t/\t" << tri2 << " (TC)\t=\t" << ac_div_tc << " (TC)\n\n";

    cout << separator;

    cout << "TEST #21 TC * AC\n";
    auto tc_mul_ac = tri1 * alg2;
    assert((std::is_same_v<decltype(tc_mul_ac), TComplex>));
    cout << tri1 << " (TC)\t*\t" << alg2 << " (AC)\t=\t" << tc_mul_ac << " (TC)\n\n";

    cout << separator;

    cout << "TEST #22 TC / AC\n";
    auto tc_div_ac = tri1 / alg2;
    assert((std::is_same_v<decltype(tc_div_ac), TComplex>));
    cout << tri1 << " (TC)\t/\t" << alg2 << " (AC)\t=\t" << tc_div_ac << " (TC)\n\n";

    cout << separator;

    cout << "TEST #23 TC * TC\n";
    auto tc_mul_tc = tri1 * tri2;
    assert((std::is_same_v<decltype(tc_mul_tc), TComplex>));
    cout << tri1 << " (TC)\t*\t" << tri2 << " (TC)\t=\t" << tc_mul_tc << " (TC)\n\n";

    cout << separator;

    cout << "TEST #24 TC / TC\n";
    auto tc_div_tc = tri1 / tri2;
    assert((std::is_same_v<decltype(tc_div_tc), TComplex>));
    cout << tri1 << " (TC)\t/\t" << tri2 << " (TC)\t=\t" << tc_div_tc << " (TC)\n\n";

    cout << separator;

    /* real numbers */
    cout << "TEST #25 AC * real\n";
    auto ac_mul_re = alg1 * real;
    assert((std::is_same_v<decltype(ac_mul_re), TComplex>));
    cout << alg1 << " (AC)\t*\t" << real << " (real)\t=\t" << ac_mul_re << " (TC)\n\n";

    cout << separator;

    cout << "TEST #26 TC * real\n";
    auto tc_mul_re = tri1 * real;
    assert((std::is_same_v<decltype(tc_mul_re), TComplex>));
    cout << tri1 << " (TC)\t*\t" << real << " (real)\t=\t" << tc_mul_re << " (TC)\n\n";

    cout << separator;

    cout << "TEST #27 AC / real\n";
    auto ac_div_re = alg1 / real;
    assert((std::is_same_v<decltype(ac_div_re), TComplex>));
    cout << alg1 << " (AC)\t/\t" << real << " (real)\t=\t" << ac_div_re << " (TC)\n\n";

    cout << separator;

    cout << "TEST #28 TC / real\n";
    auto tc_div_re = tri1 / real;
    assert((std::is_same_v<decltype(tc_div_re), TComplex>));
    cout << tri1 << " (TC)\t/\t" << real << " (real)\t=\t" << tc_div_re << " (TC)\n\n";

    cout << separator;

    cout << "TEST #29 real * AC\n";
    auto re_mul_ac = real * alg1;
    assert((std::is_same_v<decltype(re_mul_ac), TComplex>));
    cout << real << " (real)\t*\t" << alg1 << " (AC)\t=\t" << re_mul_ac << " (TC)\n\n";

    cout << separator;

    cout << "TEST #30 real * TC\n";
    auto re_mul_tc = real * tri1;
    assert((std::is_same_v<decltype(re_mul_tc), TComplex>));
    cout << real << " (real)\t*\t" << tri1 << " (TC)\t=\t" << re_mul_tc << " (TC)\n\n";

    cout << separator;

    cout << "TEST #31 real / AC\n";
    auto re_div_ac = real / alg1;
    assert((std::is_same_v<decltype(re_div_ac), TComplex>));
    cout << real << " (real)\t/\t" << alg1 << " (AC)\t=\t" << re_div_ac << " (TC)\n\n";

    cout << separator;

    cout << "TEST #32 real / TC\n";
    auto re_div_tc = real / tri1;
    assert((std::is_same_v<decltype(re_div_tc), TComplex>));
    cout << real << " (real)\t/\t" << tri1 << " (TC)\t=\t" << re_div_tc << " (TC)\n\n";

    cout << separator;

    cout << "** '+=' & '-=' ops **\n\n";

    cout << "TEST #33 AC += AC\n";
    auto ac_pluseq_ac = alg1;
    ac_pluseq_ac += alg2;
    assert((std::is_same_v<decltype(ac_pluseq_ac), AComplex>));
    cout << alg1 << " (AC)\t+=\t" << alg2 << " (AC)\t=>\t" << ac_pluseq_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #34 TC += TC\n";
    auto tc_pluseq_tc = tri1;
    tc_pluseq_tc += tri2;
    assert((std::is_same_v<decltype(tc_pluseq_tc), TComplex>));
    cout << tri1 << " (TC)\t+=\t" << tri2 << " (TC)\t=>\t" << tc_pluseq_tc << " (TC)\n\n";

    cout << separator;

    cout << "TEST #35 AC -= TC\n";
    auto ac_minuseq_tc = alg1;
    ac_minuseq_tc -= tri2;
    assert((std::is_same_v<decltype(ac_minuseq_tc), AComplex>));
    cout << alg1 << " (AC)\t-=\t" << tri2 << " (TC)\t=>\t" << ac_minuseq_tc << " (AC)\n\n";

    cout << separator;

    cout << "TEST #36 TC -= real\n";
    auto tc_minuseq_re = tri1;
    tc_minuseq_re -= real;
    assert((std::is_same_v<decltype(tc_minuseq_re), TComplex>));
    cout << tri1 << " (TC)\t-=\t" << real << " (real)\t=>\t" << tc_minuseq_re << " (TC)\n\n";

    cout << separator;

    cout << "** '*=' & '/=' ops **\n\n";

    cout << "TEST #37 AC *= AC\n";
    auto ac_muleq_ac = alg1;
    ac_muleq_ac *= alg2;
    assert((std::is_same_v<decltype(ac_muleq_ac), AComplex>));
    cout << alg1 << " (AC)\t*=\t" << alg2 << " (AC)\t=>\t" << ac_muleq_ac << " (AC)\n\n";

    cout << separator;

    cout << "TEST #38 TC *= TC\n";
    auto tc_muleq_tc = tri1;
    tc_muleq_tc *= tri2;
    assert((std::is_same_v<decltype(tc_muleq_tc), TComplex>));
    cout << tri1 << " (TC)\t*=\t" << tri2 << " (TC)\t=>\t" << tc_muleq_tc << " (TC)\n\n";

    cout << separator;

    cout << "TEST #39 AC /= TC\n";
    auto ac_diveq_tc = alg1;
    ac_diveq_tc /= tri2;
    assert((std::is_same_v<decltype(ac_diveq_tc), AComplex>));
    cout << alg1 << " (AC)\t/=\t" << tri2 << " (TC)\t=>\t" << ac_diveq_tc << " (AC)\n\n";

    cout << separator;

    cout << "TEST #40 TC /= real\n";
    auto tc_diveq_re = tri1;
    tc_diveq_re /= real;
    assert((std::is_same_v<decltype(tc_diveq_re), TComplex>));
    cout << tri1 << " (TC)\t/=\t" << real << " (real)\t=>\t" << tc_diveq_re << " (TC)\n\n";

    cout << "\n\n\ndone!!!\n";
}