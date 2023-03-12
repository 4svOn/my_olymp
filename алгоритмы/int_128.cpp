ostream& operator<<(std::ostream & dest, __int128 value) {
    std::ostream::sentry s(dest);
    if (s) {
        unsigned __int128 tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 atoint128_t(std::string const& in) {
    __int128 res = 0;
    size_t i = 0;
    bool sign = false;

    if (in[i] == '-')
    {
        ++i;
        sign = true;
    }

    if (in[i] == '+')
    {
        ++i;
    }

    for (; i < in.size(); ++i)
    {
        const char c = in[i];
        if (not std::isdigit(c))
            throw std::runtime_error(std::string("Non-numeric character: ") + c);
            res *= 10;
        res += c - '0';
    }

    if (sign)
    {
        res *= -1;
    }

    return res;
}