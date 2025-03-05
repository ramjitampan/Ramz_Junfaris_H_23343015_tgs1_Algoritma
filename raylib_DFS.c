#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAKS_NODE 7

typedef struct
{
    int hubungan[MAKS_NODE][MAKS_NODE];
    bool dikunjungi[MAKS_NODE];
} Graf;

typedef struct
{
    int data[MAKS_NODE];
    int atas;
} Tumpukan;

#define LEBAR_LAYAR 800
#define TINGGI_LAYAR 600

Vector2 posisi[MAKS_NODE] = {
    {LEBAR_LAYAR / 2, TINGGI_LAYAR / 4},
    {LEBAR_LAYAR / 3, TINGGI_LAYAR / 2.5},
    {2 * LEBAR_LAYAR / 3, TINGGI_LAYAR / 2.5},
    {LEBAR_LAYAR / 5, 3 * TINGGI_LAYAR / 4},
    {2 * LEBAR_LAYAR / 5, 3 * TINGGI_LAYAR / 4},
    {3 * LEBAR_LAYAR / 5, 3 * TINGGI_LAYAR / 4},
    {4 * LEBAR_LAYAR / 5, 3 * TINGGI_LAYAR / 4}};

void inisialisasiGraf(Graf *g)
{
    for (int i = 0; i < MAKS_NODE; i++)
    {
        for (int j = 0; j < MAKS_NODE; j++)
        {
            g->hubungan[i][j] = 0;
        }
        g->dikunjungi[i] = false;
    }

    g->hubungan[0][1] = g->hubungan[1][0] = 1;
    g->hubungan[0][2] = g->hubungan[2][0] = 1;
    g->hubungan[1][3] = g->hubungan[3][1] = 1;
    g->hubungan[1][4] = g->hubungan[4][1] = 1;
    g->hubungan[2][5] = g->hubungan[5][2] = 1;
    g->hubungan[2][6] = g->hubungan[6][2] = 1;
}

void tambahKeTumpukan(Tumpukan *tumpukan, int nilai)
{
    if (tumpukan->atas < MAKS_NODE - 1)
    {
        tumpukan->data[++tumpukan->atas] = nilai;
    }
}

int ambilDariTumpukan(Tumpukan *tumpukan)
{
    if (tumpukan->atas >= 0)
    {
        return tumpukan->data[tumpukan->atas--];
    }
    return -1;
}

bool tumpukanKosong(Tumpukan *tumpukan)
{
    return tumpukan->atas == -1;
}

void gambarGraf(Graf *g)
{
    for (int i = 0; i < MAKS_NODE; i++)
    {
        for (int j = 0; j < MAKS_NODE; j++)
        {
            if (g->hubungan[i][j])
            {
                DrawLine(posisi[i].x, posisi[i].y, posisi[j].x, posisi[j].y, GRAY);
            }
        }
    }

    for (int i = 0; i < MAKS_NODE; i++)
    {
        Color warna = g->dikunjungi[i] ? RED : BLUE;
        DrawCircleV(posisi[i], 25, warna);
        DrawText(TextFormat("%d", i), posisi[i].x - 7, posisi[i].y - 7, 20, WHITE);
    }
}

int main()
{
    Graf g;
    inisialisasiGraf(&g);

    InitWindow(LEBAR_LAYAR, TINGGI_LAYAR, "Visualisasi DFS");
    SetTargetFPS(60);

    Tumpukan tumpukan;
    tumpukan.atas = -1;
    tambahKeTumpukan(&tumpukan, 0);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !tumpukanKosong(&tumpukan))
        {
            int sekarang = ambilDariTumpukan(&tumpukan);
            if (!g.dikunjungi[sekarang])
            {
                g.dikunjungi[sekarang] = true;
            }

            for (int i = 0; i < MAKS_NODE; i++)
            {
                if (g.hubungan[sekarang][i] && !g.dikunjungi[i])
                {
                    tambahKeTumpukan(&tumpukan, i);
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        gambarGraf(&g);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
