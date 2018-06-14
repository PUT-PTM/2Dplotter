#ifndef LETTERS_H_
#define LETTERS_H_

#include "stddef.h"

// 0.5 cm ~ 36 steps
int line = 36;
int written_letters = 0;
/**
 * draw a diagonal of square x*y
 * @param direction [0..3] is a direction of line, where:
 * 0 - NE
 * 1 - SE
 * 2 - SW
 * 3 - NW
 */
void diagonal(int x, int y, int direction) {
	int temp_x = 0, temp_y = 0, scale, x_larger;
	if (x >= y) {
		scale = x / y;
		x_larger = 1;
	} else {
		scale = y / x;
		x_larger = 0;
	}
	while (temp_x < x) {
		if (direction == 0) {
			if (x_larger == 1) {
				horizontal(1 * scale);
				temp_x += 1 * scale;
			} else {
				horizontal(1);
				temp_x += 1;
			}
			if (x_larger == 0) {
				vertical(1 * scale);
				temp_y += 1 * scale;
			} else {
				vertical(1);
				temp_y += 1;
			}
		} else if (direction == 1) {
			if (x_larger == 1) {
				horizontal(1 * scale);
				temp_x += 1 * scale;
			} else {
				horizontal(1);
				temp_x += 1;
			}
			if (x_larger == 0) {
				vertical(-1 * scale);
				temp_y += 1 * scale;
			} else {
				vertical(-1);
				temp_y += 1;
			}
		} else if (direction == 2) {
			if (x_larger == 1) {
				horizontal(-1 * scale);
				temp_x += 1 * scale;
			} else {
				horizontal(-1);
				temp_x += 1;
			}
			if (x_larger == 0) {
				vertical(-1 * scale);
				temp_y += 1 * scale;
			} else {
				vertical(-1);
				temp_y += 1;
			}
		} else if (direction == 3) {
			if (x_larger == 1) {
				horizontal(-1 * scale);
				temp_x += 1 * scale;
			} else {
				horizontal(-1);
				temp_x += 1;
			}
			if (x_larger == 0) {
				vertical(1 * scale);
				temp_y += 1 * scale;
			} else {
				vertical(1);
				temp_y += 1;
			}
		}

	}
}

void draw_text(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		if ((((written_letters % 7 == 0) && (line == 36))
				|| ((written_letters % 14 == 0) && (line == 18)))
				&& written_letters > 0)
			draw_nl();
		switch (text[i]) {
		case 'A':
			draw_a();
			break;
		case 'B':
			draw_b();
			break;
		case 'C':
			draw_c();
			break;
		case 'D':
			draw_d();
			break;
		case 'E':
			draw_e();
			break;
		case 'F':
			draw_f();
			break;
		case 'G':
			draw_g();
			break;
		case 'H':
			draw_h();
			break;
		case 'I':
			draw_i();
			break;
		case 'J':
			draw_j();
			break;
		case 'K':
			draw_k();
			break;
		case 'L':
			draw_l();
			break;
		case 'M':
			draw_m();
			break;
		case 'N':
			draw_n();
			break;
		case 'O':
			draw_o();
			break;
		case 'P':
			draw_p();
			break;
		case 'R':
			draw_r();
			break;
		case 'S':
			draw_s();
			break;
		case 'T':
			draw_t();
			break;
		case 'U':
			draw_u();
			break;
		case 'V':
			draw_v();
			break;
		case 'W':
			draw_w();
			break;
		case 'X':
			draw_x();
			break;
		case 'Y':
			draw_y();
			break;
		case 'Z':
			draw_z();
			break;
		case '0':
			draw_0();
			break;
		case '1':
			draw_1();
			break;
		case '2':
			draw_2();
			break;
		case '3':
			draw_3();
			break;
		case '4':
			draw_4();
			break;
		case '5':
			draw_5();
			break;
		case '6':
			draw_6();
			break;
		case '7':
			draw_7();
			break;
		case '8':
			draw_8();
			break;
		case '9':
			draw_9();
			break;
		case '!':
			draw_exclamation_mark();
			break;
		case '?':
			draw_question_mark();
			break;
		case '.':
			draw_dot();
			break;
		case ',':
			draw_comma();
			break;
		case '-':
			draw_dash();
			break;
		case '_':
			draw_floor();
			break;
		case ' ':
			horizontal(line / 2);
			break;
		}
		written_letters++;
	}
}

void draw_a() {
	pen_up();
	vertical(-line);
	pen_down();
	vertical(0.75 * line);
	diagonal(line / 4, line / 4, 0);
	diagonal(line / 4, line / 4, 1);
	vertical(-0.75 * line);
	pen_up();
	vertical(line / 2);
	pen_down();
	horizontal(-line / 2);

// punkt (0,0) nastepnej litery
	pen_up();
	vertical(line / 2);
	horizontal(line);

}
void draw_b() {
	pen_down();
	horizontal(line / 4);
	diagonal(line / 4, line / 8, 1);
	vertical(-line / 4);
	diagonal(line / 4, line / 8, 2);
	horizontal(-line / 4);

	horizontal(line / 4);
	diagonal(line / 4, line / 8, 1);
	vertical(-line / 4);
	diagonal(line / 4, line / 8, 2);
	horizontal(-line / 4);
	vertical(line);

	pen_up();
	horizontal(line);

}
void draw_c() {
	pen_up();
	horizontal(line / 2);
	pen_down();
	horizontal(-line / 4);
	diagonal(line / 4, line / 4, 2);
	vertical(-line / 2);
	diagonal(line / 4, line / 4, 1);
	horizontal(0.25 * line);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_d() {
	pen_down();
	horizontal(line / 2);
	diagonal(line / 4, line / 4, 1);
	vertical(-line / 2);
	diagonal(line / 4, line / 4, 2);
	horizontal(-line / 2);
	vertical(line);

	pen_up();
	horizontal(line);
}
void draw_e() {
	horizontal(line / 2);
	pen_down();
	horizontal(-line / 2);
	vertical(-line);
	horizontal(line / 2);

	pen_up();
	vertical(line / 2);
	pen_down();
	horizontal(-line / 2);

	pen_up();
	vertical(line / 2);

	horizontal(line);

}
void draw_f() {
	horizontal(line / 2);
	pen_down();
	horizontal(-line / 2);
	vertical(-line);

	pen_up();
	vertical(line / 2);
	pen_down();
	horizontal(line / 2);

	pen_up();
	horizontal(-line / 2);
	vertical(line / 2);
	horizontal(line);

}
void draw_g() {
	horizontal(line / 2);
	pen_down();
	horizontal(-line / 4);
	diagonal(line / 4, line / 4, 2);
	vertical(-line / 2);
	diagonal(line / 4, line / 4, 1);
	diagonal(line / 4, line / 4, 0);
	vertical(line / 4);
	horizontal(-line / 4);

	pen_up();
	vertical(line / 2);
	horizontal(0.75 * line);
}
void draw_h() {
	pen_up();
	vertical(-line);
	pen_down();
	vertical(line);
	pen_up();
	horizontal(line / 2);
	pen_down();
	vertical(-line);
	pen_up();
	vertical(line / 2);
	pen_down();
	horizontal(-line / 2);

// punkt (0,0) nastepnej litery
	pen_up();
	vertical(line / 2);
	horizontal(line);

}
void draw_i() {
	pen_down();
	vertical(-line);
	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_j() {
	pen_down();
	horizontal(line / 2);
	vertical(-0.75 * line);
	diagonal(line / 4, line / 4, 2);
	diagonal(line / 4, line / 4, 3);

	pen_up();
	vertical(0.75 * line);
	horizontal(line);
}
void draw_k() {
	pen_down();
	vertical(-line);
	pen_up();
	vertical(line / 2);
	pen_down();
	diagonal(line / 2, line / 2, 0);
	pen_up();
	diagonal(line / 2, line / 2, 2);
	pen_down();
	diagonal(line / 2, line / 2, 1);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_l() {
	pen_down();
	vertical(-line);
	horizontal(line / 2);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_m() {
	vertical(-line);

	pen_down();
	vertical(line);
	diagonal(line / 4, line / 2, 1);
	diagonal(line / 4, line / 2, 0);
	vertical(-line);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_n() {
	vertical(-line);

	pen_down();
	vertical(line);
	diagonal(line / 2, line, 1);
	vertical(line);

	pen_up();
	horizontal(line / 2);
}
void draw_o() {
	vertical(-line / 4);
	pen_down();
	diagonal(line / 4, line / 4, 0);
	horizontal(0.25 * line);
	diagonal(line / 4, line / 4, 1);
	vertical(-0.5 * line);
	diagonal(line / 4, line / 4, 2);
	horizontal(-0.25 * line);
	diagonal(line / 4, line / 4, 3);
	vertical(0.5 * line);

	pen_up();
	vertical(line / 4);
	horizontal(line);

}
void draw_p() {
	pen_down();
	horizontal(line / 4);
	diagonal(line / 4, line / 8, 1);
	vertical(-line / 4);
	diagonal(line / 4, line / 8, 2);
	horizontal(-line / 4);

	pen_up();
	vertical(line / 2);
	pen_down();
	vertical(-line);

	pen_up();
	vertical(line);
	horizontal(line);
}
void draw_r() {
	pen_down();
	vertical(-line);
	pen_up();
	vertical(line);
	pen_down();
	pen_down();
	horizontal(line / 4);
	diagonal(line / 4, line / 8, 1);
	vertical(-line / 4);
	diagonal(line / 4, line / 8, 2);
	horizontal(-line / 4);
	diagonal(line / 2, line / 2, 1);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_s() {
	horizontal(line / 2);

	pen_down();
	horizontal(-line / 4);
	diagonal(line / 4, line / 4, 2);
	vertical(-line / 4);
	horizontal(line / 2);
	vertical(-line / 4);
	diagonal(line / 4, line / 4, 2);
	horizontal(-line / 4);

	pen_up();
	vertical(line);
	horizontal(line);

}
void draw_t() {
	pen_down();
	horizontal(line / 2);

	pen_up();
	horizontal(-line / 4);
	pen_down();
	vertical(-line);

	pen_up();
	vertical(line);
	horizontal(0.75 * line);
}
void draw_u() {
	pen_down();
	vertical(-0.75 * line);
	diagonal(line / 4, line / 4, 1);
	horizontal(0.25 * line);
	diagonal(line / 4, line / 4, 0);
	vertical(0.75 * line);

	pen_up();
	horizontal(line / 2);
}
void draw_v() {
	pen_down();
	diagonal(line / 4, line, 1);
	diagonal(line / 4, line, 0);

	pen_up();
	horizontal(line / 2);
}
void draw_w() {
	pen_down();
	vertical(-line);
	diagonal(line / 4, line / 2, 0);
	diagonal(line / 4, line / 2, 1);
	vertical(line);

	pen_up();
	horizontal(line / 2);
}
void draw_x() {
	pen_down();
	diagonal(line / 2, line, 1);
	pen_up();
	horizontal(-line / 2);
	pen_down();
	diagonal(line / 2, line, 0);

	pen_up();
	horizontal(line / 2);

	pen_up();
}
void draw_y() {
	pen_down();
	diagonal(line / 4, line / 2, 1);
	vertical(-line / 2);
	pen_up();
	vertical(line / 2);
	pen_down();
	diagonal(line / 4, line / 2, 0);

	pen_up();
	horizontal(line / 2);
}
void draw_z() {
	pen_down();
	horizontal(line / 2);
	diagonal(line / 2, line, 2);
	horizontal(line / 2);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_0() {
	pen_down();
	vertical(-line);
	horizontal(line / 2);
	vertical(line);
	horizontal(-line / 2);

	pen_up();
	horizontal(line);
}
void draw_1() {
	vertical(-0.5 * line);
	pen_down();
	diagonal(line / 2, line / 2, 0);
	vertical(-line);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_2() {
	pen_down();
	horizontal(line / 2);
	vertical(-line / 2);
	horizontal(-line / 2);
	vertical(-line / 2);
	horizontal(line / 2);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_3() {
	pen_down();
	horizontal(line / 2);
	vertical(-line / 2);
	horizontal(-line / 2);
	horizontal(line / 2);
	vertical(-line / 2);
	horizontal(-line / 2);

	pen_up();
	vertical(line);
	horizontal(1.5 * line);

}
void draw_4() {
	horizontal(line / 4);

	pen_down();
	diagonal(line / 4, line / 2, 2);
	horizontal(line / 2);
	pen_up();
	horizontal(-line / 4);
	pen_down();
	vertical(-line / 2);

	pen_up();
	vertical(line);
	horizontal(0.75 * line);
}
void draw_5() {
	horizontal(line / 2);

	pen_down();
	horizontal(-line / 2);
	vertical(-line / 2);
	horizontal(line / 2);
	vertical(-line / 2);
	horizontal(-line / 2);

	pen_up();
	vertical(line);
	horizontal(line);
}
void draw_6() {
	horizontal(line / 2);

	pen_down();
	horizontal(-line / 2);
	vertical(-line);
	horizontal(line / 2);
	vertical(line / 2);
	horizontal(-line / 2);

	pen_up();
	vertical(line / 2);
	horizontal(line);
}
void draw_7() {
	pen_down();
	horizontal(line / 2);
	vertical(-line);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_8() {
	vertical(-line / 2);

	pen_down();
	horizontal(line / 2);
	vertical(line / 2);
	horizontal(-line / 2);
	vertical(-line);
	horizontal(line / 2);
	vertical(0.75 * line);

	pen_up();
	vertical(line / 4);
	horizontal(line / 2);
}
void draw_9() {
	vertical(-line / 2);
	horizontal(line / 2);

	pen_down();
	horizontal(-line / 2);
	vertical(line / 2);
	horizontal(line / 2);
	vertical(-line);
	horizontal(-line / 2);

	pen_up();
	vertical(line);
	horizontal(line);
}

void draw_exclamation_mark() {
	pen_down();
	vertical(-0.75 * line);
	pen_up();
	vertical(-0.25 * line);
	pen_down();

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_question_mark() {
	vertical(-line / 4);
	pen_down();
	diagonal(line / 4, line / 4, 0);
	diagonal(line / 4, line / 4, 1);
	diagonal(line / 4, line / 4, 2);
	vertical(-line / 4);
	pen_up();
	vertical(-line / 4);
	pen_down();

	pen_up();
	vertical(line);
	horizontal(0.75 * line);
}
void draw_dot() {
	vertical(-line);
	pen_down();

	pen_up();
	vertical(line);
	horizontal(line);
}
void draw_comma() {
	vertical(-0.75 * line);
	pen_down();
	diagonal(line / 8, line / 4, 1);

	pen_up();
	diagonal(line / 8, line / 4, 3);
	vertical(0.75 * line);
	horizontal(line);
}
void draw_dash() {
	vertical(-line / 2);
	pen_down();
	horizontal(line / 2);

	pen_up();
	vertical(line / 2);
	horizontal(line / 2);
}
void draw_floor() {
	vertical(-line);
	pen_down();
	horizontal(line / 2);

	pen_up();
	vertical(line);
	horizontal(line / 2);
}
void draw_nl() {
	vertical(-1.5 * line);
	if (line == 18)
		horizontal(-14 * line);
	else
		horizontal(-7 * line);
	Delay(500);
}
#endif /* LETTERS_H_ */
