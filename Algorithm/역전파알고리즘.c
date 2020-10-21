#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define INPUT_NUM 2
#define HIDDEN_NUM 4

void init_hidden(double*, double*, double);
void init_output_line(double*, double*, double);
void compute_hidden_in(double*, double*, double*, double*);
void compute_hidden(double*, double*);
double compute_output(double, double*, double*, double*);
double compute_delta(double, double, double);
void back_output_line(double, double, double*, double*, double*);
void compute_delta_input_in(double, double*, double*);
void compute_delta_input(double*, double*, double*);
void back_input_line(double, double*, double*, double*, double*);
void update_input(double*, double*);
void update_output(double*, double*);

//출처: https://wooyoo.tistory.com/7 [My Story]

int main() {
    double input[INPUT_NUM * INPUT_NUM][INPUT_NUM];
    double output[INPUT_NUM * INPUT_NUM];
    double output_in[INPUT_NUM * INPUT_NUM];
    double output_real[INPUT_NUM * INPUT_NUM];
    double learn_rate = 0.02;
    double input_line[INPUT_NUM][HIDDEN_NUM];
    double input_line_update[INPUT_NUM][HIDDEN_NUM];
    double output_line[HIDDEN_NUM];
    double output_line_update[HIDDEN_NUM];
    double hidden_in[HIDDEN_NUM];
    double hidden[HIDDEN_NUM];
    double dummy[HIDDEN_NUM];
    double dummy_update[HIDDEN_NUM];
    double output_unit;
    double output_unit_update;
    double stop_flag[INPUT_NUM * INPUT_NUM];
    double scale_factor;
    double delta_val[INPUT_NUM * INPUT_NUM];
    double delta_input[HIDDEN_NUM];
    double delta_input_in[HIDDEN_NUM];
    int i, j;
    double gg = 0;
    FILE* fp;
    char string[256];
    char* ptoken;

    //input : 2개, hidden layer : 4개, output : 1개로 이루어져있고,
    //입력 데이터는 aaa.txt에서 읽는다.
    //input data는 (1, 1), (-1, 1), (1, -1), (-1, -1)이고, output target값은 XOR값이 true이면
    //0.8이고, false일 경우 -0.8의 값을 갖는다.

    if ((fp = fopen("aaa.txt", "rt")) == NULL) {
        printf("파일을 열 수 없습니다. \n");
    }
    else {
        i = 0;
        while (!feof(fp)) {
            j = 0;
            fgets(string, 256, fp);
            ptoken = strtok(string, ",");
            while (ptoken != NULL) {
                input[i][j] = (double)atoi(ptoken);
                printf("%s\t", ptoken);
                /* 두번째 이후 호출시에는 첫번째 파라메타를 NULL로 합니다. */
                ptoken = strtok(NULL, ",");
                j++;
            }
            printf("\n");
            i++;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            printf("%.3lf \n", input[i][j]);
        }
    }

    fclose(fp);

    for (i = 0; i < INPUT_NUM * INPUT_NUM; i++) {
        if (input[i][0] == input[i][1]) { //output 계산
            output_real[i] = -0.8;
        }
        else {
            output_real[i] = 0.8;
        }
    }

    scale_factor = 0.7 * pow(HIDDEN_NUM, (double)1 / INPUT_NUM); //scale factor 초기값 지정(nguyen-widrow)
    init_hidden(input_line, dummy, scale_factor);
    init_output_line(output_line, &output_unit, scale_factor);

    //계산
    do {
        gg = 0;
        for (i = 0; i < INPUT_NUM * INPUT_NUM; i++) {
            compute_hidden_in(input[i], input_line, dummy, hidden_in);
            compute_hidden(hidden, hidden_in);
            output[i] = compute_output(output_unit, hidden, output_line, &output_in[i]);
            delta_val[i] = compute_delta(output_real[i], output[i], output_in[i]);
            back_output_line(learn_rate, delta_val[i], hidden, output_line_update, &output_unit_update);
            compute_delta_input_in(delta_val[i], output_line, delta_input_in);
            compute_delta_input(delta_input_in, hidden_in, delta_input);
            back_input_line(learn_rate, delta_input, input[i], input_line_update, dummy_update);
            update_input(input_line, input_line_update);
            update_output(output_line, output_line_update);
            stop_flag[i] = output_real[i] - output[i];
            gg += pow(stop_flag[i], 2);
            printf("output[%d] : %.6lf \n", i, output[i]);
        }
    } while (gg > 0.05 && gg != 0);

    for (i = 0; i < 4; i++) {
        printf("%.6lf \n", output[i]);
    }


    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return 0;
}

//인풋 라인 초기화
void init_hidden(double* input_line, double* dummy, double scale_factor) {
    int i, j, int_val;
    int double_val;
    srand(time(0));
    int_val = scale_factor;
    double_val = (scale_factor - (int)scale_factor) * 1000;

    for (i = 0; i < INPUT_NUM; i++) {
        for (j = 0; j < HIDDEN_NUM; j++) {
            *input_line = rand() % (int_val + 1);
            *input_line += (rand() % double_val) * 0.001;
            if (rand() % 2 == 0)
                *input_line = -(*input_line);
            input_line++;
            if (i == 0) {
                *dummy = rand() % (int_val + 1);
                *dummy += (rand() % double_val) * 0.001;
                if (rand() % 2 == 0)
                    *dummy = -*(dummy);
                dummy++;
            }
        }
    }
}

//아웃풋 라인 초기화 
void init_output_line(double* output_line, double* output_unit, double scale_factor) {
    int i;

    int int_val, double_val;
    srand(time(0));
    int_val = scale_factor;
    double_val = (scale_factor - (int)scale_factor) * 1000;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *output_line = rand() % (int_val + 1);
        *output_line += (rand() % double_val) * 0.001;
        if (rand() % 2 == 0)
            *output_line = -(*output_line);
        output_line++;
    }
    *output_unit = rand() % (int_val + 1);
    *output_unit += (rand() % double_val) * 0.001;
    if (rand() % 2 == 0)
        *output_unit = -(*output_unit);
}

//히든 레이어 in값 계산(Step 4)
void compute_hidden_in(double input[INPUT_NUM], double input_line[INPUT_NUM][HIDDEN_NUM], double dummy[HIDDEN_NUM], double hidden_in[HIDDEN_NUM]) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++)
        hidden_in[i] = dummy[i] + input[0] * input_line[0][i] + input[1] * input_line[1][i];
}

//히든 레이어 값 계산(Activation)
void compute_hidden(double* hidden, double* hidden_in) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *hidden = (2 / (1 + exp((-*hidden_in)))) - 1;
        hidden++;
        hidden_in++;
    }
}

//아웃풋 계산(Step 5)
double compute_output(double output_unit, double* hidden, double* output_line, double* output_in) {
    int i;
    double output;
    *output_in = output_unit;

    for (i = 0; i < HIDDEN_NUM; i++) {
        *output_in += (*hidden) * (*output_line);
        hidden++;
        output_line++;
    }
    output = (2 / (1 + exp((-(*output_in))))) - 1;

    return output;
}

//델타k 값 계산(Step 6-1)
double compute_delta(double output_real, double output, double output_in) {
    double delta_val;
    double diff_in;
    diff_in = (1 + (2 / (1 + exp(-output_in)) - 1)) * (1 - (2 / (1 + exp(-output_in)) - 1)) / 2;
    delta_val = (output_real - output) * diff_in;

    return delta_val;
}

//backpropagation 에러 계산(Step 6-2 : output_line 업데이트)
void back_output_line(double learn_rate, double delta_val, double* hidden, double* output_line_update, double* output_unit_update) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *output_line_update = learn_rate * delta_val * (*hidden);
        output_line_update++;
        hidden++;
    }
    *output_unit_update = learn_rate * delta_val;
}

//delta input_in 계산(Step 7-1)
void compute_delta_input_in(double delta_val, double* output_line, double* delta_input_in) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *delta_input_in = delta_val * (*output_line);

        delta_input_in++;
        output_line++;
    }
}

//delta input 계산(Step 7-2)
void compute_delta_input(double* delta_input_in, double* hidden_in, double* delta_input) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *delta_input = (*delta_input_in) * ((1 + (2 / (1 + exp(-(*hidden_in))) - 1)) * (1 - (2 / (1 + exp(-(*hidden_in))) - 1)) / 2);
        delta_input_in++;
        delta_input++;
        hidden_in++;
    }
}

//backpropagation 에러 계산(Step 7-3 : input_line 업데이트)
void back_input_line(double learn_rate, double* delta_input, double* input, double* input_line_update, double* dummy_update) {
    int i, j;
    for (i = 0; i < INPUT_NUM; i++) {
        for (j = 0; j < HIDDEN_NUM; j++) {
            *input_line_update = learn_rate * (*delta_input) * (*input);
            if (i == 0) {
                *dummy_update = learn_rate * (*delta_input);
                dummy_update++;
            }
            input_line_update++;
            delta_input++;
        }
        input++;
        delta_input = delta_input - HIDDEN_NUM;
    }
}

//최종 input라인 업데이트
void update_input(double* input_line, double* input_line_update) {
    int i, j;
    for (i = 0; i < INPUT_NUM; i++) {
        for (j = 0; j < HIDDEN_NUM; j++) {
            *input_line = *input_line + *input_line_update;
            input_line++;
            input_line_update++;
        }
    }
}

//최종 output라인 업데이트
void update_output(double* output_line, double* output_line_update) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *output_line = *output_line + *output_line_update;
        output_line++;
        output_line_update++;
    }
}



출처: https://wooyoo.tistory.com/7 [My Story]