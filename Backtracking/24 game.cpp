bool find24(vector<double> vec) {


  if (vec.size() == 1) {
    return abs(vec[0] - 24.0) <= 0.0000001;
  }


  vector<char> operations = {'+', '-', '*', '/'};

  for (int i = 0; i < vec.size(); ++i) {

    for (int j = 0; j < vec.size(); ++j) {
      if (i == j) {
        continue;
      }

      vector<double> res;
      for (int k = 0; k < vec.size(); ++k) {
        if (k != i && k != j) {
          res.push_back(vec[k]);
        }
      }

      for (auto op : operations) {
        if ((op == '+' || op == '*') && i > j) {

          continue;
        }
        if (op == '/' && vec[j] == 0.0) {
          continue;
        }

        switch (op) {
        case '+':
          res.push_back(vec[i] + vec[j]);
          break;
        case '-':
          res.push_back(vec[i] - vec[j]);
          break;
        case '*':
          res.push_back(vec[i] * vec[j]);
          break;
        case '/':
          res.push_back(vec[i] / vec[j]);
          break;
        }

        if (find24(res)) {
          return true;
        }

        res.pop_back();
      }
    }
  }
  return false;
}

bool judge(vector<int> &nums) {
  vector<double> vec;
  for (auto n : nums) {

    vec.push_back(n * 1.0);
  }

  return find24(vec);
}
