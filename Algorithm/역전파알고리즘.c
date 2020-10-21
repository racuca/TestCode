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

//��ó: https://wooyoo.tistory.com/7 [My Story]

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

    //input : 2��, hidden layer : 4��, output : 1���� �̷�����ְ�,
    //�Է� �����ʹ� aaa.txt���� �д´�.
    //input data�� (1, 1), (-1, 1), (1, -1), (-1, -1)�̰�, output target���� XOR���� true�̸�
    //0.8�̰�, false�� ��� -0.8�� ���� ���´�.

    if ((fp = fopen("aaa.txt", "rt")) == NULL) {
        printf("������ �� �� �����ϴ�. \n");
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
                /* �ι�° ���� ȣ��ÿ��� ù��° �Ķ��Ÿ�� NULL�� �մϴ�. */
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
        if (input[i][0] == input[i][1]) { //output ���
            output_real[i] = -0.8;
        }
        else {
            output_real[i] = 0.8;
        }
    }

    scale_factor = 0.7 * pow(HIDDEN_NUM, (double)1 / INPUT_NUM); //scale factor �ʱⰪ ����(nguyen-widrow)
    init_hidden(input_line, dummy, scale_factor);
    init_output_line(output_line, &output_unit, scale_factor);

    //���
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

//��ǲ ���� �ʱ�ȭ
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

//�ƿ�ǲ ���� �ʱ�ȭ 
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

//���� ���̾� in�� ���(Step 4)
void compute_hidden_in(double input[INPUT_NUM], double input_line[INPUT_NUM][HIDDEN_NUM], double dummy[HIDDEN_NUM], double hidden_in[HIDDEN_NUM]) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++)
        hidden_in[i] = dummy[i] + input[0] * input_line[0][i] + input[1] * input_line[1][i];
}

//���� ���̾� �� ���(Activation)
void compute_hidden(double* hidden, double* hidden_in) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *hidden = (2 / (1 + exp((-*hidden_in)))) - 1;
        hidden++;
        hidden_in++;
    }
}

//�ƿ�ǲ ���(Step 5)
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

//��Ÿk �� ���(Step 6-1)
double compute_delta(double output_real, double output, double output_in) {
    double delta_val;
    double diff_in;
    diff_in = (1 + (2 / (1 + exp(-output_in)) - 1)) * (1 - (2 / (1 + exp(-output_in)) - 1)) / 2;
    delta_val = (output_real - output) * diff_in;

    return delta_val;
}

//backpropagation ���� ���(Step 6-2 : output_line ������Ʈ)
void back_output_line(double learn_rate, double delta_val, double* hidden, double* output_line_update, double* output_unit_update) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *output_line_update = learn_rate * delta_val * (*hidden);
        output_line_update++;
        hidden++;
    }
    *output_unit_update = learn_rate * delta_val;
}

//delta input_in ���(Step 7-1)
void compute_delta_input_in(double delta_val, double* output_line, double* delta_input_in) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *delta_input_in = delta_val * (*output_line);

        delta_input_in++;
        output_line++;
    }
}

//delta input ���(Step 7-2)
void compute_delta_input(double* delta_input_in, double* hidden_in, double* delta_input) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *delta_input = (*delta_input_in) * ((1 + (2 / (1 + exp(-(*hidden_in))) - 1)) * (1 - (2 / (1 + exp(-(*hidden_in))) - 1)) / 2);
        delta_input_in++;
        delta_input++;
        hidden_in++;
    }
}

//backpropagation ���� ���(Step 7-3 : input_line ������Ʈ)
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

//���� input���� ������Ʈ
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

//���� output���� ������Ʈ
void update_output(double* output_line, double* output_line_update) {
    int i;
    for (i = 0; i < HIDDEN_NUM; i++) {
        *output_line = *output_line + *output_line_update;
        output_line++;
        output_line_update++;
    }
}



��ó: https://wooyoo.tistory.com/7 [My Story]