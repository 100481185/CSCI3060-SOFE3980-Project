int main(int argc, char **argv) {
    int powerOff = false;
    do {
        powerOff = control();
        if (powerOff < 0)
            powerOff = printMsg(powerOff);

    } while (!powerOff);

}

bool printMsg(int powerOff) {
    std::cout << powerOff << std::endl;
}
