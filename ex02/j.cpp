#include "./PmergeMe.hpp"

/* OCCF: constructor */
PmergeMe::PmergeMe(int ac, char** av)
{
    if (ac < 3)
        throw std::logic_error("Error: arguments are more than 3");
    this->_checkNPush(ac, av);
    this->_calculateJacobsthalArr(ac / 2);
}

/* OCCF: destructor */
PmergeMe::~PmergeMe() {}


/* member function: public */
void PmergeMe::runFordJohnson(void)
{
    clock_t start, end;
    double  timeTaken;

    start = clock();
    this->_mergeInsertionSort(this->_vec);
    end = clock();
    timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << this->_vec.size()
              << " elements with std::[vector] : " << timeTaken << " us" << std::endl;

    start = clock();
    this->_mergeInsertionSort(this->_dq);
    end = clock();
    timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << this->_vec.size()
              << " elements with std::[deque]  : " << timeTaken << " us" << std::endl;
}

const std::vector<long>& PmergeMe::getVec(void)
{
    return this->_vec;
}

const std::deque<long>& PmergeMe::getDq(void)
{
    return this->_dq;
}


/* member function: private */
/* vector mergeInsertionSort function */
void PmergeMe::_mergeInsertionSort(std::vector<long>& vec)
{
    // 1. devide to main-chain and pending-chain
    if (vec.size() < 2)
        return;

    size_t                                  halfSize = vec.size() / 2;
    std::vector<long>                       mainChain;
    std::vector<long>                       pendingChain;
    std::vector< std::pair<long, long> >    vecPair;
    for (size_t i = 0; i < halfSize; ++i) {
        if (vec[i] > vec[i + halfSize]) {
            mainChain.push_back(vec[i]);
            pendingChain.push_back(vec[i + halfSize]);
        } else {
            mainChain.push_back(vec[i + halfSize]);
            pendingChain.push_back(vec[i]);
        }
        vecPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
    }
    if (vec.size() % 2 == 1)
        pendingChain.push_back(vec.back());

    // 2. recursive for main-chain and synchronize pending-chain from sorted-main-chain
    this->_mergeInsertionSort(mainChain);
    if (mainChain.size() != 1) {
        for (size_t i = 0; i < mainChain.size(); ++i) {
            size_t findIdx = 0;
            while (mainChain[i] != vecPair[findIdx].first) findIdx++;
            pendingChain[i] = vecPair[findIdx].second;
        }
    }

    // 3. insert pending-chain to main-chain by sorting
    std::vector<long> sortedVec(mainChain);
    sortedVec.insert(sortedVec.begin(), pendingChain.front());
    size_t jacobIdx = 1;            // index(0) is already inserted to main
    size_t prev = 0, curr = 1;
    while (curr <= pendingChain.size() - 1) {
        curr = this->_jacobNum[jacobIdx++] - 1;
        if (curr >= pendingChain.size())
            curr = pendingChain.size() - 1;
        for (size_t i = curr; i > prev; --i) {
            size_t range;
            if (vec.size() % 2 == 1 && i == pendingChain.size() - 1)
                range = sortedVec.size();
            else
                range = std::lower_bound(sortedVec.begin(), sortedVec.end(), mainChain[i]) - sortedVec.begin();
            size_t insertPos = this->_searchInsertionPos(sortedVec, range, pendingChain[i]);
            sortedVec.insert(sortedVec.begin() + insertPos, pendingChain[i]);
        }
        prev = curr++;
    }
    vec = sortedVec;    // synchronization
}

size_t PmergeMe::_searchInsertionPos(std::vector<long>& sortedVec, size_t right, long insertValue)
{
    size_t left = 0;

    while (left < right) {
        size_t mid = (left + right) / 2;
        if (sortedVec[mid] > insertValue)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}


/* deque mergeInsertionSort function */
void PmergeMe::_mergeInsertionSort(std::deque<long>& dq)
{
    // 1. devide to main-chain and pending-chain
    if (dq.size() < 2)
        return;

    size_t                                  halfSize = dq.size() / 2;
    std::deque<long>                       mainChain;
    std::deque<long>                       pendingChain;
    std::deque< std::pair<long, long> >    dqPair;
    for (size_t i = 0; i < halfSize; ++i) {
        if (dq[i] > dq[i + halfSize]) {
            mainChain.push_back(dq[i]);
            pendingChain.push_back(dq[i + halfSize]);
        } else {
            mainChain.push_back(dq[i + halfSize]);
            pendingChain.push_back(dq[i]);
        }
        dqPair.push_back(std::make_pair(mainChain[i], pendingChain[i]));
    }
    if (dq.size() % 2 == 1)
        pendingChain.push_back(dq.back());

    // 2. recursive for main-chain and synchronize pending-chain from sorted-main-chain
    this->_mergeInsertionSort(mainChain);
    if (mainChain.size() != 1) {
        for (size_t i = 0; i < mainChain.size(); ++i) {
            size_t findIdx = 0;
            while (mainChain[i] != dqPair[findIdx].first) findIdx++;
            pendingChain[i] = dqPair[findIdx].second;
        }
    }

    // 3. insert pending-chain to main-chain by sorting
    std::deque<long> sortedDq(mainChain);
    sortedDq.insert(sortedDq.begin(), pendingChain.front());
    size_t jacobIdx = 1;            // index(0) is already inserted to main
    size_t prev = 0, curr = 1;
    while (curr <= pendingChain.size() - 1) {
        curr = this->_jacobNum[jacobIdx++] - 1;
        if (curr >= pendingChain.size())
            curr = pendingChain.size() - 1;
        for (size_t i = curr; i > prev; --i) {
            size_t range;
            if (dq.size() % 2 == 1 && i == pendingChain.size() - 1)
                range = sortedDq.size();
            else
                range = std::lower_bound(sortedDq.begin(), sortedDq.end(), mainChain[i]) - sortedDq.begin();
            size_t insertPos = this->_searchInsertionPos(sortedDq, range, pendingChain[i]);
            sortedDq.insert(sortedDq.begin() + insertPos, pendingChain[i]);
        }
        prev = curr++;
    }
    dq = sortedDq;    // synchronization
}

size_t PmergeMe::_searchInsertionPos(std::deque<long>& sortedVec, size_t right, long insertValue)
{
    size_t left = 0;

    while (left < right) {
        size_t mid = (left + right) / 2;
        if (sortedVec[mid] > insertValue)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}


/* using in constructor */
void PmergeMe::_checkNPush(int count, char** args)
{
    for (int i = 1; i < count; i++) {
        char* pos;
        long num = strtol(args[i], &pos, 10);
        if (*pos != '\0')
            throw std::logic_error("Error: arguments are must be integer");
        if (num <= 0)
            throw std::logic_error("Error: all numbers must be positive integer");
        this->_vec.push_back(num);
        this->_dq.push_back(num);
    }
}

void PmergeMe::_calculateJacobsthalArr(size_t count)
{
    if (this->_jacobNum.empty() == false)
        this->_jacobNum.clear();
    this->_jacobNum.push_back(1);
    this->_jacobNum.push_back(3);
    size_t curr = 3, now = 2;
    while (curr <= count) {
        curr = this->_jacobNum[now - 1] + 2 * this->_jacobNum[now - 2];
        this->_jacobNum.push_back(curr);
        ++now;
    }
}


/* just for printing or debugging */
void PmergeMe::printContainer(const std::vector<long>& vec, const std::string& vecName)
{
    std::cout << "[ " << vecName << " ]: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << ">> size(" << vec.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::vector< std::pair<long, long> >& vecPair, const std::string& pairName)
{
    std::cout << "[ " << pairName << " ]: ";
    for (size_t i = 0; i < vecPair.size(); ++i)
        std::cout << "(" << vecPair[i].first << ", " << vecPair[i].second << ") ";
    std::cout << ">> size(" << vecPair.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::deque<long>& dq, const std::string& dqName)
{
    std::cout << "[ " << dqName << " ]: ";
    for (size_t i = 0; i < dq.size(); ++i)
        std::cout << dq[i] << " ";
    std::cout << ">> size(" << dq.size() << ")" << std::endl;
}

void PmergeMe::printContainer(const std::deque< std::pair<long, long> >& dqPair, const std::string& pairName)
{
    std::cout << "[ " << pairName << " ]: ";
    for (size_t i = 0; i < dqPair.size(); ++i)
        std::cout << "(" << dqPair[i].first << ", " << dqPair[i].second << ") ";
    std::cout << ">> size(" << dqPair.size() << ")" << std::endl;
}

/* check is sorted and print results */
void PmergeMe::printIsSorted(const std::vector<long>& vec)
{
    bool flag = true;
    std::vector<long>::const_iterator it;
    for (it = vec.begin() + 1; it != vec.end(); ++it) {
        if (*(it - 1) > *it) {
            flag = false;
            break;
        }
    }
    std::cout << "[ vector sorted ]: ";
    if (flag == true) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}

void PmergeMe::printIsSorted(const std::deque<long>& dq)
{
    bool flag = true;
    std::deque<long>::const_iterator it;
    for (it = dq.begin() + 1; it != dq.end(); ++it) {
        if (*(it - 1) > *it) {
            flag = false;
            break;
        }
    }
    std::cout << "[ deque sorted ] : ";
    if (flag == true) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
}